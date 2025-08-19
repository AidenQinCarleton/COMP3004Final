#ifndef device_h
#define device_h

// The Radotech device

#include <QTimer>
#include <QProgressBar>

#include "battery.h"

class Device {
    private:
        bool isOn;
        Battery battery;
        bool connection;
        bool skinContact;
        QTimer depletion;
        QProgressBar* progress;

    public:
        // Constructor
        Device();
        
        // getters and setters
        bool getIsOn();
        bool setIsOn(bool isOn);
        int getBatteryLevel();
        void setCharge(bool charge);
        void setSkinContact(bool contact);
        bool getSkinContact(void);

        // Take readings
        float takeReading();
        // Connect to an app
        void connect(bool con);
        bool getConnection(void);

        // Depleting the battery
        void depleteBattery(void);

        void setProgressBar(QProgressBar* progress);
};

#endif
