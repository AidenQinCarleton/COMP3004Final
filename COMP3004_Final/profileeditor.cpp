#include "profileeditor.h"
#include "globals.h"

const QStringList ProfileEditor::GENDER_STRINGS = {"Male", "Female", "Other"};

ProfileEditor::ProfileEditor(QWidget *parent, ProfileSelector* selector)
    : QWidget{parent}, selector(selector)
{
    layout = new QFormLayout(this);
    this->setLayout(layout);

    fName = new QLineEdit(this);
    layout->addRow(QString("First Name:"), fName);

    lName = new QLineEdit(this);
    layout->addRow(QString("Last Name:"), lName);

    gender = new QComboBox(this);
    gender->insertItems(0, ProfileEditor::GENDER_STRINGS);
    layout->addRow(QString("Gender:"), gender);

    weight = new QLineEdit(this);
    layout->addRow(QString("Weight:"), weight);

    height = new QLineEdit(this);
    layout->addRow(QString("Height:"), height);

    birthdate = new QDateEdit(this);
    layout->addRow(QString("Date of Birth:"), birthdate);

    phoneNumber = new QLineEdit(this);
    layout->addRow(QString("Phone Number:"), phoneNumber);

    email = new QLineEdit(this);
    layout->addRow(QString("Email:"), email);

    password = new QLineEdit(this);
    layout->addRow(QString("Password"), password);

    submit = new QPushButton("submit", this);
    connect(submit, &QPushButton::released, this, &ProfileEditor::submitProfile);
    layout->addWidget(submit);
}

void ProfileEditor::setFeilds(const ProfileInfo &info) {
    fName->setText(info.fName);
    lName->setText(info.lName);
    gender->setCurrentIndex(info.gender);
    weight->setText(QString("%1").arg(info.weight));
    height->setText(QString("%1").arg(info.height));
    birthdate->setDate(info.birthdate);
    phoneNumber->setText(info.phoneNumber);
    email->setText(info.email);
    password->setText(info.password);
}

void ProfileEditor::clearFeilds(){
    fName->clear();
    lName->clear();
    gender->setCurrentIndex(0);
    weight->clear();
    height->clear();
    birthdate->clear();
    phoneNumber->clear();
    email->clear();
    password->clear();
}

void ProfileEditor::submitProfile(){
    ProfileInfo info = generateProfileInfo();
    if (profileIndex == -1){
        globals::app->addProfile(info);
    } else {
        globals::app->updateProfile(info, profileIndex);
    }
    selector->updateProfileDisplay();
    globals::pagesWidget->setCurrentIndex(pages::profileSelector);
}

void ProfileEditor::setProfileIndex(int newProfileIndex)
{
    profileIndex = newProfileIndex;
}

ProfileInfo ProfileEditor::generateProfileInfo() const{
    ProfileInfo info;
    info.fName = fName->text();
    info.lName = lName->text();
    info.gender = static_cast<Gender>(gender->currentIndex());
    info.weight = weight->text().toDouble();
    info.height = height->text().toDouble();
    info.birthdate = birthdate->date();
    info.phoneNumber = phoneNumber->text();
    info.email = email->text();
    info.password = password->text();
    return info;
}
