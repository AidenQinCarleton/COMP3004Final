#ifndef RECOMMENDATIONS_H
#define RECOMMENDATIONS_H

#include <QString>

class Recommendations {

// Enum for indexing the recommendations safely
enum RecType {
    REC_HYPERACTIVE,
    REC_INSUFFICIENCY,
    REC_DIET,
    REC_DIET_RECOMMENDATIONS,
    REC_FOOD,
    REC_EXCLUDE,
    REC_GENERAL_RECOMMENDATIONS,
    REC_ACTIVITY,
    REC_SUPPLEMENTS,
    RECOMMENDATIONS_SIZE
};

private:
    int upperBound = 70;
    int lowerBound = 50;

    // Array of QStrings containing recommendations
    QString recommendations[RECOMMENDATIONS_SIZE];

public:
    // Constructor
    Recommendations() = default;
    Recommendations(float arr[24]);
    QString getRecommendation(int index);
};

#endif // RECOMMENDATIONS_H
