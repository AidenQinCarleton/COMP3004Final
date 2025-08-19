#ifndef battery_h
#define battery_h

// The battery class
#include <QMessageBox>

constexpr int BATTERY_DEPLETION_RATE = 1;
constexpr int BATTERY_CHARGE_RATE = 5;

class Device;

class Battery {
    private:
        // The battery level
        int level;
        // If the battery is charging
        bool isCharging;
        // If the battery is depleting
        bool isDepleting;
        // message box for low battery warning
        QMessageBox message;
        // if warning message has been displayed
        bool batteryWarning;


    public:
        // Constructor
        Battery();
        // Getters and setters
        int getLevel();
        void setDeplete(bool deplete);
        void setCharge(bool charge);
        bool getDeplete();
        bool getCharge();

        // Battery charging depletion
        void updateCharge(void);
};

#endif
