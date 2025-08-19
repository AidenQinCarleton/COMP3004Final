#ifndef GLOBALS_H
#define GLOBALS_H

#include "QStackedWidget"
#include "app.h"

namespace globals{
    extern App* app;
    extern QStackedWidget* pagesWidget;
}

// indexs for pages to allow for navagation
namespace pages{
    extern int profileSelector;
    extern int profileEditor;
    extern int profileViewer;
    extern int exam;
    extern int deviceViewer;
}

#endif // GLOBALS_H
