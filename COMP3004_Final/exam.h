#ifndef EXAM_H
#define EXAM_H

#include <QWidget>
#include <QPushButton>
#include <QStringList>
#include <QLabel>
#include <QFormLayout>
#include <QMessageBox>

#include "examresults.h"

class Exam : public QWidget
{
    Q_OBJECT
public:
    explicit Exam(QWidget *parent = nullptr);

    void reset();

private slots:
    void getReading();
    void setSkinContact();
    void startExam();

private:
    QFormLayout* layout;
    QLabel* instructionLabel;
    QLabel* readingNumber;
    QLabel* skin;
    QLabel* readingTaken;
    QPushButton* reading;
    QPushButton* skinContact;
    QPushButton* newExam;
    QMessageBox message;

    bool readingThisSkinContact;
    float inputs[EXAM_RESULTS_SIZE];
    int currReading;

    static QStringList instructions;
};

#endif // EXAM_H
