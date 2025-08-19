#include "app.h"

// Constructor
App::App() {
    currProfile = -1;
}

// This member function stores an exam result
void App::StoreExamResult(ExamResults exam) {
    profiles[currProfile].addExam(exam);
}

// This member function determines an exam result REWRITE WHEN INTEGRATING
ExamResults App::CreateResult() const {

    // Creating array of results from data
    float calculations[EXAM_RESULTS_SIZE];
    srand(time(NULL));
    for (int i = EX_LEFT_LUNG; i < EXAM_RESULTS_SIZE; i++) {

        // First random value
        float val = ((float)rand() / float(RAND_MAX)) * 160;
        calculations[i] = val;
    }

    // Creating exam results
    QDateTime date = QDateTime::currentDateTime();
    ExamResults results(calculations);
    return results;
}

int App::numProfiles() const{
    return profiles.size();
}

void App::addProfile(const ProfileInfo &info){
    profiles.push_back(Profile(info));
}

void App::deleteProfile(const int index){
    profiles.erase(profiles.begin() + index);

}

void App::setCurrentProfile(const int index){
   currProfile = index;
}

void App::updateProfile(const ProfileInfo &info, int index){
    profiles[index].updateProfile(info);
}

const ProfileInfo& App::getProfileInfo(const int index) const{
    return profiles[index].getInfo();
}

Profile& App::getProfile(const int index){
    return profiles[index];
}

Profile &App::getCurrentProfile(){
    return profiles[currProfile];

}

QStringList App::profileNames() const {
    QStringList list;
    for (auto& profile: profiles){
        list.append(profile.getFName() + " " + profile.getLName());
    }
    return list;
}

bool App::loggedIn() const {
    return currProfile >= 0;
}

void App::addProgressBar(QProgressBar* progress){
    device.setProgressBar(progress);
}

bool App::hasSkinContact(){
    return device.getSkinContact();
}

Device* App::getDevice() {
    return &device;
}

void App::setSkinContact(bool skin){
    device.setSkinContact(skin);
}

bool App::deviceIsAvailable(){
    return device.getConnection() && device.getIsOn();
}

float App::getReading(){
    return device.takeReading();
}
