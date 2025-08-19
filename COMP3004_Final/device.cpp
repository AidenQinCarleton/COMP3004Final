#include "device.h"
#include "app.h"

// Constructor
Device::Device()
{
    this->isOn = false;
    connection = false;
    depletion.setInterval(10000);
    depletion.callOnTimeout(std::bind(&Device::depleteBattery, this));
    skinContact = false;
}

// getters and setters
bool Device::getIsOn(){
    return this->isOn;
}

bool Device::setIsOn(bool on)
{
    this->isOn = on;

    // Either starting or stopping battery depletion based on device status
    if (isOn) {
        depletion.start();
    } else {
        depletion.stop();
        connection = false;
    }

    return isOn;
}

int Device::getBatteryLevel()
{
    return this->battery.getLevel();
}

void Device::setCharge(bool charge)
{
    this->battery.setCharge(charge);
}


// Take readings
float Device::takeReading()
{ 
   if (skinContact && isOn && connection)
   {
    // Random float value between 0 and 160
    return ((float)rand() / float(RAND_MAX)) * 160;
   }
   return -1;

}

void Device::setSkinContact(bool contact)
{
    this->skinContact = contact;
}

bool Device::getSkinContact()
{
    return this->skinContact;
}

// Connect to an app
void Device::connect(bool con)
{
    if (isOn){
        connection = con;
    }
}

// Getting the device connection
bool Device::getConnection() {
    return connection;
}

// Depleting or charging the battery
void Device::depleteBattery() {

    this->battery.setDeplete(isOn);

    // Depleting the battery
    this->battery.updateCharge();

    if (battery.getLevel() == 0){
        this->isOn = false;
        this->connection = false;
    }

    this->progress->setValue(battery.getLevel());
}

void Device::setProgressBar(QProgressBar *progress){
    this->progress = progress;
}
