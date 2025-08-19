#include "battery.h"
#include "device.h"

// Constructor
Battery::Battery() {
    this->level = 100;
    this->isCharging = false;
    this->isDepleting = false;
    this->batteryWarning = false;
}

// Getters and setters
int Battery::getLevel() {
    return this->level;
}

void Battery::setDeplete(bool deplete) {
    this->isDepleting = deplete;
}

void Battery::setCharge(bool charge) {
    this->isCharging = charge;
}

bool Battery::getDeplete() {
    return this->isDepleting;
}

bool Battery::getCharge() {
    return this->isCharging;
}

void Battery::updateCharge() {
    if (this->isCharging) {
        this->level += BATTERY_CHARGE_RATE;
        batteryWarning = false;
        if (this->level > 100) {
            this->level = 100;
        }
    }

    if (this->isDepleting) {
        this->level -= BATTERY_DEPLETION_RATE;
        if (this->level <= 0) {
            this->level = 0;
            message.setText("battery is dead");
            message.setInformativeText("please charge the device to continue");
            message.exec();
        } else if (this->level <= 10 && !batteryWarning){
            batteryWarning = true;
            message.setText("battery is low");
            message.setInformativeText("please charge the device before it dies");
            message.exec();
        }
    }
}
