#include "profileviewer.h"
#include "globals.h"

// Constructor
ProfileViewer::ProfileViewer(QWidget *parent) : QWidget{parent} {

    // Setting initial values
    LOWER_INFO_BOUND = 0.0;
    UPPER_INFO_BOUND = 200.0;

    // Setting up layout
    QWidget* container = new QWidget(this);
    layout = new QVBoxLayout(container);
    layout->setSizeConstraint(QLayout::SetMinimumSize);

    // Creating name label
    name = new QLabel("Name: ", this);
    layout->addWidget(name);

    // Creating a dropdown box for exam history
    prevExams = new QComboBox(this);
    layout->addWidget(prevExams);
    connect(prevExams, &QComboBox::textActivated, this, &ProfileViewer::DrawGraph);

    // Creating a test bar chart series
    bars = new QBarSeries(this);
    leftData = new QBarSet("Left Side", this);
    rightData = new QBarSet("Right Side", this);
    bars->append(leftData);
    bars->append(rightData);

    // Creating a new chart
    QString titleText;
    titleText.append("Exam Results: ---");
    chart = new QChart();
    chart->addSeries(bars);
    chart->setTitle(titleText);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setParent(this);

    // Creating QStringlist for labels
    QStringList labels;
    for (int i = 0; i < 12; i++) {
        labels.append(this->resultInfo[i]);
    }

    // Creating chart x axis
    x = new QBarCategoryAxis(this);
    x->append(labels);
    chart->addAxis(x, Qt::AlignBottom);
    bars->attachAxis(x);

    // Creating chart y axis
    y = new QValueAxis(this);
    y->setRange(LOWER_INFO_BOUND, UPPER_INFO_BOUND);
    chart->addAxis(y, Qt::AlignLeft);
    bars->attachAxis(y);

    // Adjusting chart values
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setVisible(true);

    // Setting the view of the chart
    examChart = new QChartView(chart);
    examChart->setMinimumHeight(400);
    examChart->setRenderHint(QPainter::Antialiasing);
    examChart->setVisible(true);
    layout->addWidget(examChart);

    // Setting recommendations
    recScroll = new QScrollArea(this);
    recScroll->setVisible(true);
    recScroll->setMinimumHeight(200);
    recs = new Recommendation(recScroll, this);
    layout->addWidget(recScroll);

    // Scroll area so all widgets are accessible
    profileScroll = new QScrollArea(this);
    profileScroll->setWidgetResizable(true);
    profileScroll->setMinimumWidth(750);
    profileScroll->setWidget(container);

    // Layout for scroll area
    QVBoxLayout* scrollLayout = new QVBoxLayout(this);
    scrollLayout->addWidget(profileScroll);
    this->setLayout(scrollLayout);
}

// Setter for the profile
void ProfileViewer::SetCurrProfile() {
    currProfile = &globals::app->getCurrentProfile();
    if (currProfile == NULL) {
        qInfo("true");
        return;
    }

    // Clearing old information
    prevExams->clear();
    while(leftData->count() > 0) {
        leftData->remove(leftData->count() - 1);
        rightData->remove(rightData->count() - 1);
    }
    recs->clearRecommendations();

    // Setting the name label
    QString nameText;
    nameText.append("Name: ");
    nameText.append(currProfile->getFName());
    nameText.append(" ");
    nameText.append(currProfile->getLName());
    name->setText(nameText);

    QString exam = "";

    // Adding exam results to list of possible selections
    for (int i = currProfile->getExamNum() - 1; i >= 0; i--) {
        exam = currProfile->getExam(i)->GetDate().toString();
        prevExams->addItem(exam);
    }

    // draw most recent exam
    if (exam != ""){
        DrawGraph(exam);
    }
}

void ProfileViewer::DrawGraph(QString text) {

    // Looking for the correct graph to display
    QDateTime searchDate = QDateTime::fromString(text);
    ExamResults* ex = currProfile->getExam(searchDate);

    // Setting the chart title
    QString titleText;
    titleText.append("Exam Result: ");
    titleText.append(ex->GetDate().toString());
    chart->setTitle(titleText);

    // Removing old info
    while(leftData->count() > 0) {
        leftData->remove(leftData->count() - 1);
        rightData->remove(rightData->count() - 1);
    }

    // Drawing graph
    for (int i = 0; i < EXAM_RESULTS_SIZE; i += 2) {
        leftData->append(ex->GetResult(ExResType(i)));
        rightData->append(ex->GetResult(ExResType(i + 1)));
    }
    bars->append(leftData);
    bars->append(rightData);

    // Setting the recommendations
    recs->clearRecommendations();
    recs->setRecommendations(ex);
}
