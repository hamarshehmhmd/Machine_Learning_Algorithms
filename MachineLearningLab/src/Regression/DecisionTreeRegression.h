#ifndef DECISION_TREE_REGRESSION_H
#define DECISION_TREE_REGRESSION_H
#include "../DataUtils/DataLoader.h"
#include "../Evaluation/Metrics.h"
#include "../Utils/Node.h"
#include <string>
#include <vector>
#include <utility>


                                    /// DecisionTreeRegression class definition ///


class DecisionTreeRegression {
public:
    DecisionTreeRegression(int min_samples_split = 2, int max_depth = 100, int n_feats = 0);
    void fit(std::vector<std::vector<double>>& X, std::vector<double>& y);
    std::vector<double> predict(std::vector<std::vector<double>>& X);
    std::tuple<double, double, double, double, double, double, 
        std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>> 
        runDecisionTreeRegression(const std::string& filePath, int trainingRatio);

private:
    int min_samples_split;
    int max_depth;
    int n_feats;
    Node* root;

    Node* growTree(std::vector<std::vector<double>>& X, std::vector<double>& y, int depth = 0);
    double meanSquaredError(std::vector<double>& y, std::vector<double>& X_column, double split_thresh);
    double mean(std::vector<double>& values);
    double traverseTree(std::vector<double>& x, Node* node);
};

#endif  // DECISION_TREE_REGRESSION_H





