#ifndef PROFILESELECTOR_H
#define PROFILESELECTOR_H

#include <QWidget>

#include "QFormLayout"
#include "QComboBox"
#include "QPushButton"
#include "QMessageBox"
#include "QLineEdit"

#include "profileeditor.h"

class ProfileEditor;

#include "profileviewer.h"

class ProfileSelector : public QWidget
{
    Q_OBJECT
public:
    explicit ProfileSelector(QWidget *parent = nullptr);


    void setEditor(ProfileEditor *newEditor);
public slots:
    void updateProfileDisplay();
private slots:
    void createProfile(void);
    void selectProfile(void);
    void updateProfile(void);
    void deleteProfile(void);

private:
    QFormLayout* layout;
    QComboBox* users;
    QLineEdit* password;
    QPushButton* createButton;
    QPushButton* selectButton;
    QPushButton* updateButton;
    QPushButton* deleteButton;
    QMessageBox message;

    ProfileEditor* editor = nullptr;

    bool verifyPassword(const Profile& profile);
};

#endif // PROFILESELECTOR_H
