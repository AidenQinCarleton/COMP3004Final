#ifndef app_h
#define app_h

// The app class

#include <QObject>
#include <QVector>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QDebug>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtCharts>

#include <math.h>
#include <random>

#include "examresults.h"
#include "device.h"
#include "profile.h"
#include <vector>

class App {
    private:
        Device device;
        std::vector<Profile> profiles;
        int currProfile;

        // Storage for exam results
        std::vector<ExamResults> examRecords;

        // List of items pertaining to creating the exam display widget
        const char* resultInfo[12] {
            "Lung",
            "Pericardium",
            "Heart",
            "Small Intestine",
            "Immunity",
            "Large Intestine",
            "Pancreas",
            "Liver",
            "Kidneys",
            "Genitourinary System",
            "Gallbladder",
            "Stomach"
        };

    public:
        // Constructor
        App();

        // Getters and setters
        Device *getDevice();

        // Member storing an exam result
        void StoreExamResult(ExamResults exam);

        // creates an exam result without an exam
        ExamResults CreateResult() const;

        // return the number of profiles
        int numProfiles(void) const;

        // adds a profile to the profiles vector
        void addProfile(const ProfileInfo& info);

        // removes a profile from the profiles vector
        void deleteProfile(const int index);

        // sets the current profile
        void setCurrentProfile(const int index);

        // updates a profile in the profiles vector
        void updateProfile(const ProfileInfo& info, int index);

        // return a profiles info struct
        const ProfileInfo& getProfileInfo(const int index) const;

        // return a refernce to a profile
        Profile& getProfile(const int index);

        // return the current profile
        Profile &getCurrentProfile();

        // creates the display info for profile selection
        QStringList profileNames() const;

        //checks if the user is logged in to a profile
        bool loggedIn() const;

        //adds the progress bar to the device to update it
        void addProgressBar(QProgressBar* progress);

        // check if the device has skin contact
        bool hasSkinContact();

        // sets if the device has skin contact
        void setSkinContact(bool skin);

        // check if the device is available
        bool deviceIsAvailable();

        // get a reading from the device
        float getReading();
};

#endif
