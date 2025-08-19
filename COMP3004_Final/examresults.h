#ifndef EXAMRESULTS_H
#define EXAMRESULTS_H

#include <QDateTime>
#include <QDebug>

#include "recommendations.h"

// Enum for efficiently indexing exam results
enum ExResType {
    EX_LEFT_LUNG,
    EX_RIGHT_LUNG,
    EX_LEFT_PERICARDIUM,
    EX_RIGHT_PERICARDIUM,
    EX_LEFT_HEART,
    EX_RIGHT_HEART,
    EX_LEFT_SMALL_INTESTINE,
    EX_RIGHT_SMALL_INTESTINE,
    EX_LEFT_IMMUNITY,
    EX_RIGHT_IMMUNITY,
    EX_LEFT_LARGE_INTESTINE,
    EX_RIGHT_LARGE_INTESTINE,
    EX_LEFT_PANCREAS,
    EX_RIGHT_PANCREAS,
    EX_LEFT_LIVER,
    EX_RIGHT_LIVER,
    EX_LEFT_GENITOURINARY_SYSTEM,
    EX_LEFT_KIDNEY,
    EX_RIGHT_KIDNEY,
    EX_RIGHT_GENITOURINARY_SYSTEM,
    EX_LEFT_GALLBLADDER,
    EX_RIGHT_GALLBLADDER,
    EX_LEFT_STOMACH,
    EX_RIGHT_STOMACH,
    EXAM_RESULTS_SIZE
};

class ExamResults {

private:
    // The time the exam was taken
    QDateTime date;

    // An array containing the results
   float results[EXAM_RESULTS_SIZE];

    // The recommendations that go along with the exam result
    Recommendations recommendations;
public:
    // Constructors
    ExamResults(float data[EXAM_RESULTS_SIZE]);
    ExamResults(ExamResults* ex);

    //Getter for result amounts
    float GetResult(ExResType resInd);

    QString GetRecommendation(int index);

    // Getter for the date of the exam
    QDateTime GetDate(void);
};

#endif // EXAMRESULTS_H
