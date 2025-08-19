#include "profile.h"

Profile::Profile(ProfileInfo info): info(info) {}

const QString &Profile::getFName() const
{
    return info.fName;
}

const QString &Profile::getLName() const
{
    return info.lName;
}

const QString &Profile::getPassword() const
{
    return info.password;
}


void Profile::updateProfile(const ProfileInfo &info){
    this->info.fName = info.fName;
    this->info.lName = info.lName;
    this->info.gender = info.gender;
    this->info.weight = info.weight;
    this->info.height = info.height;
    this->info.birthdate = info.birthdate;
    this->info.phoneNumber = info.phoneNumber;
    this->info.email = info.email;
    this->info.password = info.password;
}

const ProfileInfo &Profile::getInfo() const
{
    return info;
}

void Profile::addExam(const ExamResults &newExam) {
    results.push_back(newExam);
}

int Profile::getExamNum() {
    return results.size();
}

ExamResults* Profile::getExam(QDateTime date) {
    for (unsigned long i = 0; i < results.size(); i++) {
        if (results[i].GetDate().toString() == date.toString()) {
            for (int j = 0; j < EXAM_RESULTS_SIZE; j++) {
                qInfo("%f", results[i].GetResult(ExResType(j)));
            }
            return &results[i];
        }
    }
    return nullptr;
}

ExamResults* Profile::getExam(int index) {
    return &results[index];
}
