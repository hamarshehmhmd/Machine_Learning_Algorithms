#ifndef KNNREGRESSION_H
#define KNNREGRESSION_H

#include "../DataUtils/DataLoader.h"
#include "../Utils/SimilarityFunctions.h"
#include "../Evaluation/Metrics.h"
#include <string>
#include <vector>
#include <utility>

                                    /// KNNRegression class definition ///

class KNNRegression {
public:
    KNNRegression(int k);

    void fit(const std::vector<std::vector<double>>& X_train, const std::vector<double>& y_train);
    std::vector<double> predict(const std::vector<std::vector<double>>& X_test) const;
    std::tuple<double, double, double, double, double, double,
        std::vector<double>, std::vector<double>,
        std::vector<double>, std::vector<double>>
        runKNNRegression(const std::string& filePath, int trainingRatio);

private:
    std::vector<std::vector<double>> X_train_;
    std::vector<double> y_train_;
    int k_;

};


#endif // KNNREGRESSION_H


