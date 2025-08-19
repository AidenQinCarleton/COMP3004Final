#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include <QObject>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>
#include "examresults.h"

class Recommendation : public QWidget {
    Q_OBJECT

public:
    explicit Recommendation(QScrollArea *scrollArea, QWidget *parent = nullptr);

    void populateRecommendations();
    void setRecommendations(ExamResults* ex);
    void clearRecommendations();

private:
    QScrollArea *scrollArea;
    QVBoxLayout *contentLayout;
    QVector<QLabel*> recStrings;

    // List of items pertaining to recommendations
    static QString recTypes[9];
};
#endif // RECOMMENDATION_H
