#ifndef PROFILE_H
#define PROFILE_H

#include "QString"
#include "QDate"
#include <vector>
#include "examresults.h"

enum Gender{
    male,
    female,
    other
};

struct ProfileInfo {
    QString fName;
    QString lName;
    Gender gender;
    double weight;
    double height;
    QDate birthdate;
    QString phoneNumber;
    QString email;
    QString password;
};

class Profile
{
public:
    Profile(ProfileInfo info);
    const QString &getFName() const;

    const QString &getLName() const;


    const QString &getPassword() const;

    void updateProfile(const ProfileInfo& info);

    const ProfileInfo &getInfo() const;

    ExamResults* getExam(QDateTime date);
    ExamResults* getExam(int index);
    int getExamNum(void);
    void addExam(const ExamResults &newExam);

private:
    ProfileInfo info;
    std::vector<ExamResults> results;
};

#endif // PROFILE_H
