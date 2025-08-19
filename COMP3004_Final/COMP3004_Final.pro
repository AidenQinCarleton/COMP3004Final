QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += charts

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app.cpp \
    deviceviewer.cpp \
    exam.cpp \
    globals.cpp \
    main.cpp \
    mainwindow.cpp \
    battery.cpp \
    device.cpp \
    examresults.cpp \
    profile.cpp \
    profileeditor.cpp \
    profileselector.cpp \
    profileviewer.cpp \
    recommendations.cpp \
    recommendation.cpp \


HEADERS += \
    app.h \
    deviceviewer.h \
    exam.h \
    globals.h \
    mainwindow.h \
    battery.h \
    device.h \
    examresults.h \
    profile.h \
    profileeditor.h \
    profileselector.h \
    profileviewer.h \
    recommendations.h \
    recommendation.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
