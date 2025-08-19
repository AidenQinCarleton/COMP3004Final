#include "examresults.h"

// Constructor
ExamResults::ExamResults(float data[EXAM_RESULTS_SIZE]):
    date(QDateTime::currentDateTime()){

    // Assigning data
    for (int i = 0; i < EXAM_RESULTS_SIZE; i++) {
        results[i] = data[i];
    }

    recommendations = Recommendations(results);
}

// Copy constructor
ExamResults::ExamResults(ExamResults* ex) {
    // Setting result values
    for (int i = 0; i < EXAM_RESULTS_SIZE; i++) {
        results[i] = ex->GetResult(ExResType(i));
    }

    // Determining recommendations
   recommendations = Recommendations(results);
}

// Getter for the exam results
float ExamResults::GetResult(ExResType resInd) {
    return results[resInd];
}

// Getter for the date
QDateTime ExamResults::GetDate() {
    return date;
}

// Getting a recommendation
QString ExamResults::GetRecommendation(int index) {
    return recommendations.getRecommendation(index);
}
