#ifndef PROFILEEDITOR_H
#define PROFILEEDITOR_H

#include <QWidget>
#include "QFormLayout"
#include "QLineEdit"
#include "QComboBox"
#include "QDateEdit"
#include "QPushButton"

#include "profile.h"
#include "profileselector.h"

class ProfileSelector;

class ProfileEditor : public QWidget
{
    Q_OBJECT
public:
    explicit ProfileEditor(QWidget *parent = nullptr, ProfileSelector* selector = nullptr);

    void setFeilds(const ProfileInfo& info);
    void clearFeilds(void);

    void setProfileIndex(int newProfileIndex);

private slots:
    void submitProfile();

private:
    QFormLayout* layout;
    QLineEdit* fName;
    QLineEdit* lName;
    QComboBox* gender;
    QLineEdit* weight;
    QLineEdit* height;
    QDateEdit* birthdate;
    QLineEdit* phoneNumber;
    QLineEdit* email;
    QLineEdit* password;
    QPushButton* submit;

    static const QStringList GENDER_STRINGS;
    ProfileSelector* selector;
    int profileIndex;

    ProfileInfo generateProfileInfo() const;
};

#endif // PROFILEEDITOR_H
