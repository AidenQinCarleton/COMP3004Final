#ifndef DEVICEVIEWER_H
#define DEVICEVIEWER_H

#include <QWidget>

#include "QVBoxLayout"
#include "QComboBox"
#include "QPushButton"
#include "QLabel"
#include "QtCharts"

#include "app.h"
#include "examresults.h"

class DeviceViewer : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceViewer(QWidget *parent = nullptr);

private slots:
    void TurnOnDevice();
    void ConnectDevice();


private:

    // Buttons
    QVBoxLayout* layout;
    QPushButton* turnOnButton;
    QPushButton* connectButton;

};

#endif // DEVICEVIEWER_H
