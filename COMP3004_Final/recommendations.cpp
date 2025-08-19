#include "recommendations.h"

Recommendations::Recommendations(float arr[24]) {
    float sum = 0.0f;

    for (int i = 0; i < 24; ++i)
    {
        sum += arr[i];
    }

    float average = sum / 24;

    // Generate a response based on the average value
    if (average > upperBound) {
        recommendations[REC_HYPERACTIVE] = "Hyperactivity detected. Adjust diet and activity levels provided below.";
        recommendations[REC_INSUFFICIENCY] = "No insufficiencies detected.";
        recommendations[REC_DIET] = "Consume a balanced diet rich in fiber and low in sugar.";
        recommendations[REC_DIET_RECOMMENDATIONS] = "Include more leafy greens, whole grains, and lean protein in your meals.";
        recommendations[REC_FOOD] = "Recommended foods: Spinach, Quinoa, Salmon, and Berries.";
        recommendations[REC_EXCLUDE] = "Avoid sugary drinks, processed snacks, and high-fat fast foods.";
        recommendations[REC_GENERAL_RECOMMENDATIONS] = "Maintain hydration and avoid excessive caffeine or alcohol.";
        recommendations[REC_ACTIVITY] = "Engage in light exercises like yoga or walking for 30 minutes daily.";
        recommendations[REC_SUPPLEMENTS] = "Consider adding Vitamin B-complex and Magnesium supplements to your routine.";
    }
    else if (average < lowerBound) {
        recommendations[REC_HYPERACTIVE] = "No hyperactivities detected. Please proceed to the next section.";
        recommendations[REC_INSUFFICIENCY] = "Insufficiency detected. Consider supplements and a better diet.";
        recommendations[REC_DIET] = "Increase calorie intake with nutrient-dense foods like nuts and seeds.";
        recommendations[REC_DIET_RECOMMENDATIONS] = "Add healthy fats, complex carbohydrates, and protein-rich foods to your meals.";
        recommendations[REC_FOOD] = "Recommended foods: Avocado, Sweet Potatoes, Chicken Breast, and Bananas.";
        recommendations[REC_EXCLUDE] = "Limit consumption of empty-calorie foods like candies and sodas.";
        recommendations[REC_GENERAL_RECOMMENDATIONS] = "Focus on meal timing and regular snacks to meet energy requirements.";
        recommendations[REC_ACTIVITY] = "Engage in moderate-strength training to improve muscle mass.";
        recommendations[REC_SUPPLEMENTS] = "Consider Omega-3 fatty acids and Iron supplements if needed.";
    }
    else {
        recommendations[REC_HYPERACTIVE] = "No hyperactivities detected. Please proceed to the next section.";
        recommendations[REC_INSUFFICIENCY] = "No insufficiencies detected. Maintain your current lifestyle.";
        recommendations[REC_DIET] = "Continue with a balanced diet, ensuring adequate vitamins and minerals.";
        recommendations[REC_DIET_RECOMMENDATIONS] = "Monitor portion sizes and avoid over-restricting essential nutrients.";
        recommendations[REC_FOOD] = "Recommended foods: Broccoli, Lentils, Eggs, and Oranges.";
        recommendations[REC_EXCLUDE] = "Minimize junk food intake and prioritize home-cooked meals.";
        recommendations[REC_GENERAL_RECOMMENDATIONS] = "Stay hydrated, practice mindfulness, and get 7-8 hours of sleep.";
        recommendations[REC_ACTIVITY] = "Maintain an active lifestyle with a mix of cardio and strength exercises.";
        recommendations[REC_SUPPLEMENTS] = "No additional supplements needed unless advised by a healthcare professional.";
    }
}

QString Recommendations::getRecommendation(int index) {
    return recommendations[index];
}
