#include "profileselector.h"
#include "globals.h"

ProfileSelector::ProfileSelector(QWidget *parent)
    : QWidget{parent}
{
    layout = new QFormLayout(this);
    this->setLayout(layout);


    users = new QComboBox(this);
    layout->addRow("profiles:", users);

    password = new QLineEdit(this);
    layout->addRow("password:", password);

    createButton = new QPushButton("create", this);
    layout->addWidget(createButton);
    connect(createButton, &QPushButton::released, this, &ProfileSelector::createProfile);

    selectButton = new QPushButton("select", this);
    layout->addWidget(selectButton);
    connect(selectButton, &QPushButton::released, this, &ProfileSelector::selectProfile);

    updateButton = new QPushButton("update", this);
    layout->addWidget(updateButton);
    connect(updateButton, &QPushButton::released, this, &ProfileSelector::updateProfile);

    deleteButton = new QPushButton("delete", this);
    layout->addWidget(deleteButton);
    connect(deleteButton, &QPushButton::released, this, &ProfileSelector::deleteProfile);
}

void ProfileSelector::updateProfileDisplay(){
    users->clear();
    users->insertItems(0, globals::app->profileNames());
}

void ProfileSelector::createProfile(){
    if (globals::app->numProfiles() < 5){
        editor->clearFeilds();
        editor->setProfileIndex(-1);
        globals::pagesWidget->setCurrentIndex(pages::profileEditor);
    } else {
        message.setText("maximium profiles reached");
        message.setInformativeText("maximium of 5 profiles allowed, delete a profile to make space");
        message.exec();
    }

}

void ProfileSelector::selectProfile(){
    if (globals::app->numProfiles() < 1) {
        message.setText("no profiles exist");
        message.setInformativeText("create a profile to delete");
        message.exec();
        return;
    }
    int index = users->currentIndex();
    const Profile& profile = globals::app->getProfile(index);
    if (verifyPassword(profile)){
        globals::app->setCurrentProfile(index);
    }
}

void ProfileSelector::updateProfile() {
    if (globals::app->numProfiles() < 1) {
        message.setText("no profiles exist");
        message.setInformativeText("create a profile to update");
        message.exec();
        return;
    }
    int index = users->currentIndex();
    const Profile& profile = globals::app->getProfile(index);
    if (verifyPassword(profile)){
        editor->setProfileIndex(index);
        editor->setFeilds(profile.getInfo());
        globals::pagesWidget->setCurrentIndex(pages::profileEditor);
    }
}

void ProfileSelector::deleteProfile(){
    if (globals::app->numProfiles() < 1) {
        message.setText("no profiles exist");
        message.setInformativeText("create a profile to delete");
        message.exec();
        return;
    }
    int index = users->currentIndex();
    const Profile& profile = globals::app->getProfile(index);
    if (verifyPassword(profile)){
        globals::app->deleteProfile(index);
        updateProfileDisplay();
    }
}

bool ProfileSelector::verifyPassword(const Profile& profile){
    QString profilePassword = profile.getPassword();
    QString userPassword = password->text();
    bool match = profilePassword == userPassword;
    if (!match){
        message.setText("password does not match profile");
        message.setInformativeText("double check the password to make sure it is correct");
        message.exec();
    }
    return match;
}

void ProfileSelector::setEditor(ProfileEditor *newEditor)
{
    editor = newEditor;
}
