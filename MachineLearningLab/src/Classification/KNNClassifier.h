#ifndef KNNCLASSIFIER_H
#define KNNCLASSIFIER_H

#include "../DataUtils/DataLoader.h"
#include "../Utils/SimilarityFunctions.h"
#include "../Evaluation/Metrics.h"
#include <string>
#include <vector>
#include <utility>


                                            /// KNNClassifier class definition ///


class KNNClassifier {
public:
    KNNClassifier(int k);
    void fit(const std::vector<std::vector<double>>& X_train, const std::vector<double>& y_train);
    std::vector<double> KNNClassifier::predict(const std::vector<std::vector<double>>& X_test) const;
    std::tuple<double, double, std::vector<double>, std::vector<double>,
        std::vector<double>, std::vector<double>>
        runKNNClassifier(const std::string& filePath, int trainingRatio);


private:
    std::vector<std::vector<double>> X_train_;
    std::vector<double> y_train_;
    int k_;

};

#endif // KNNCLASSIFIER_H
