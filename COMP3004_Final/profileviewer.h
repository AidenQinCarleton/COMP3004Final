#ifndef PROFILEVIEWER_H
#define PROFILEVIEWER_H

#include <QWidget>

#include "QVBoxLayout"
#include "QComboBox"
#include "QPushButton"
#include "QLabel"
#include "QtCharts"

#include "app.h"
#include "examresults.h"
#include "recommendation.h"

class ProfileViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ProfileViewer(QWidget *parent = nullptr);

public slots:
    void SetCurrProfile();

private slots:
    void DrawGraph(QString date);


private:
    // App and current profile
    Profile* currProfile;

    // Layout
    QVBoxLayout* layout;
    QComboBox* prevExams;
    QScrollArea* profileScroll;

    // Labels for person and current page status
    QLabel* name;

    // Values for exam charts
    QChartView* examChart;
    QBarSeries* bars;
    QBarSet* leftData;
    QBarSet* rightData;
    QString* titleText;
    QChart* chart;
    QStringList* labels;
    QBarCategoryAxis* x;
    QValueAxis* y;

    // Recommendations section
    QScrollArea* recScroll;
    Recommendation* recs;

    // Bounds for data
    float LOWER_INFO_BOUND;
    float UPPER_INFO_BOUND;

    // List of items pertaining to creating the exam display widget
    const char* resultInfo[12] {
        "Lung",
        "Pericardium",
        "Heart",
        "Small Intestine",
        "Immunity",
        "Large Intestine",
        "Pancreas",
        "Liver",
        "Kidneys",
        "Genitourinary System",
        "Gallbladder",
        "Stomach"
    };

    // Values for helping with taking exams
    float newExamResult[EXAM_RESULTS_SIZE];
    int numResultsTaken;
};

#endif
