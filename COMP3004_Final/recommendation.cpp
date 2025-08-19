#include "recommendation.h"


QString Recommendation::recTypes[9] {
        "Hyperactivity",
        "Insufficiency",
        "Diet",
        "Diet Recommendations",
        "Food",
        "Exclude",
        "General Recommendations",
        "Activity",
        "Supplements"
    };

Recommendation::Recommendation(QScrollArea *scrollArea, QWidget *parent)
    : QWidget(parent), scrollArea(scrollArea) {
    // Ensure the scroll area is valid
    if (!scrollArea) {
        qWarning("scrollArea is null!");
        return;
    }

    // Populate recommendations
    populateRecommendations();
}

void Recommendation::populateRecommendations() {
    // Create a new widget that will be added to the scroll area
    QWidget *contentWidget = new QWidget(this);

    // Create a layout for the content widget
    contentLayout = new QVBoxLayout(contentWidget);

    // Add 24 labels for recommendations
    for (int i = 0; i < 9; ++i) {
        QLabel *label = new QLabel(recTypes[i], this);
        label->setText(label->text() + " Recommendation: ");
        recStrings.push_back(label);
        contentLayout->addWidget(label);
    }

    // Set the layout of the content widget
    contentWidget->setLayout(contentLayout);

    // Set the content widget to be the scroll area widget
    scrollArea->setWidget(contentWidget);

    // Make the content widget resizable within the scroll area
    scrollArea->setWidgetResizable(true);
}

void Recommendation::setRecommendations(ExamResults* ex) {

    for (int i = 0; i < recStrings.size(); i++) {
        QString newText(recTypes[i]);
        newText.append(" Recommendations: ");
        newText.append(ex->GetRecommendation(i));
        recStrings[i]->setText(newText);
    }
}

void Recommendation::clearRecommendations() {

    for (int i = 0; i < recStrings.size(); i++) {
        QString newText(recTypes[i]);
        newText.append(" Recommendations: ");
        recStrings[i]->setText(newText);
    }
}
