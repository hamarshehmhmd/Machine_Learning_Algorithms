#ifndef METRICS_H
#define METRICS_H
#include <vector>

                                               /// Metrics class definition ///
            

class Metrics {
public:
    // Regression evaluation metrics
    static double meanAbsoluteError(const std::vector<double>& trueValues, const std::vector<double>& predictedValues);
    static double rootMeanSquaredError(const std::vector<double>& trueValues, const std::vector<double>& predictedValues);
    static double Metrics::rSquared(const std::vector<double>& trueValues, const std::vector<double>& predictedValues);

    // Classification evaluation metrics
    static double accuracy(const std::vector<double>& trueLabels, const std::vector<double>& predictedLabels);
    static double precision(const std::vector<double>& trueLabels, const std::vector<double>& predictedLabels, int classLabel);
    static double recall(const std::vector<double>& trueLabels, const std::vector<double>& predictedLabels, int classLabel);
    static double f1Score(const std::vector<double>& trueLabels, const std::vector<double>& predictedLabels, int classLabel);
    static std::vector<std::vector<int>> confusionMatrix(const std::vector<double>& trueLabels, const std::vector<double>& predictedLabels, const int numClasses);
     
    // Clustering evaluation metrics
    static double calculateDaviesBouldinIndex(const std::vector<std::vector<double>>& X, const std::vector<int>& labels);
    static double calculateSilhouetteScore(const std::vector<std::vector<double>>& X, const std::vector<int>& labels);

};

#endif // METRICS_H
