#include "exam.h"
#include "globals.h"

QStringList Exam::instructions = {"please start a new exam", "put the device on the skin",
                                  "remove the device to move to the next point"};

Exam::Exam(QWidget *parent)
    : QWidget{parent}
{
    layout = new QFormLayout(this);
    this->setLayout(layout);

    instructionLabel = new QLabel(this);
    layout->addWidget(instructionLabel);
    instructionLabel->setText(instructions[0]);

    readingNumber = new QLabel(this);
    layout->addWidget(readingNumber);
    readingNumber->setText("current reading: " + QString::number(currReading+1));

    skin = new QLabel(this);
    layout->addWidget(skin);
    skin->setText(QString("device is not on skin"));

    readingTaken = new QLabel(this);
    layout->addWidget(readingTaken);
    readingTaken->setText("reading has not been taken this skin press");

    reading = new QPushButton("take reading", this);
    layout->addWidget(reading);
    connect(reading, &QPushButton::released, this, &Exam::getReading);
    reading->setDisabled(true);

    skinContact = new QPushButton("move device", this);
    layout->addWidget(skinContact);
    connect(skinContact, &QPushButton::released, this, &Exam::setSkinContact);
    skinContact->setDisabled(true);

    newExam = new QPushButton("start new exam", this);
    layout->addWidget(newExam);
    connect(newExam, &QPushButton::released, this, &Exam::startExam);
}

void Exam::reset(){
    reading->setDisabled(true);
    skinContact->setDisabled(true);
    currReading = 0;
    readingNumber->setText("current reading: " + QString::number(currReading+1));
    readingThisSkinContact = false;
    instructionLabel->setText(instructions[0]);
}

void Exam::getReading(){
    if (!globals::app->deviceIsAvailable()){
        message.setText("can't find device");
        message.setInformativeText("make sure the device is paired and turned on");
        message.exec();
        return;
    }
    if (readingThisSkinContact){
        message.setText("reading already taken for this point");
        message.setInformativeText("move the device to the next point");
        message.exec();
        return;
    }
    if (!globals::app->hasSkinContact()){
        message.setText("device not on skin");
        message.setInformativeText("move the device to the next point to take the reading");
        message.exec();
        return;
    }
    float value = globals::app->getReading();
    if (value == -1){
        message.setText("error when reading from device");
        message.setInformativeText("verify the device is functioning properly and try again");
        message.exec();
        return;
    }
    inputs[currReading] = value;
    currReading++;
    if (currReading == EXAM_RESULTS_SIZE){
        ExamResults result = ExamResults(inputs);
        globals::app->StoreExamResult(result);
        reset();
    } else {
        readingNumber->setText("current reading: " + QString::number(currReading+1));
        instructionLabel->setText(instructions[2]);
        readingThisSkinContact = true;
        readingTaken->setText("reading has been taken this skin press");
    }

}

void Exam::setSkinContact(){
    if (!globals::app->deviceIsAvailable()){
        message.setText("can't find device");
        message.setInformativeText("make sure the device is paired and turned on");
        message.exec();
        return;
    }
    bool contact = !globals::app->hasSkinContact();
    globals::app->setSkinContact(contact);
    readingThisSkinContact = false;
    readingTaken->setText("reading has not been taken this skin press");
    if (contact){
        skin->setText(QString("device is on skin"));
    }else{
        skin->setText(QString("device is not on skin"));
    }
}

void Exam::startExam(){
    reading->setDisabled(false);
    skinContact->setDisabled(false);
    currReading = 0;
    readingThisSkinContact = false;
    int currInstruction = globals::app->hasSkinContact() +1;
    instructionLabel->setText(instructions[currInstruction]);
}
