#include "deviceviewer.h"
#include "globals.h"

// Constructor
DeviceViewer::DeviceViewer(QWidget *parent)
    : QWidget{parent}
{

    // Setting up layout
    layout = new QVBoxLayout(this);
    this->setLayout(layout);

    // Creating a button that turns the device on
    turnOnButton = new QPushButton("Turn On", this);
    layout->addWidget(turnOnButton);
    connect(turnOnButton, &QPushButton::pressed, this, &DeviceViewer::TurnOnDevice);

    // Creating a button that connects the device to that app
    connectButton = new QPushButton("Connect Device", this);
    layout->addWidget(connectButton);
    connect(connectButton, &QPushButton::pressed, this, &DeviceViewer::ConnectDevice);
}

void DeviceViewer::TurnOnDevice() {
    // Getting the current state of the device
    bool state = globals::app->getDevice()->getIsOn();

    // Changing the connection status
    if (!state) {
        globals::app->getDevice()->setIsOn(true);
        turnOnButton->setText("Turn Off");
    } else {
        globals::app->getDevice()->setIsOn(false);
        globals::app->getDevice()->connect(false);
        turnOnButton->setText("Turn On");
    }
}

void DeviceViewer::ConnectDevice() {
    globals::app->getDevice()->connect(true);
}

