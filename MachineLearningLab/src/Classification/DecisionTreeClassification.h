#ifndef DECISION_TREE_CLASSIFICATION_H
#define DECISION_TREE_CLASSIFICATION_H
#include "../DataUtils/DataLoader.h"
#include "../Evaluation/Metrics.h"
#include "../Utils/Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <vector>
#include <map>

                                        /// DecisionTreeClassification class definition ///


class DecisionTreeClassification {
public:
    DecisionTreeClassification(int min_samples_split = 2, int max_depth = 100, int n_feats = NULL);
    void fit(std::vector<std::vector<double>>& X, std::vector<double>& y);
    std::vector<double> predict(std::vector<std::vector<double>>& X);
    std::tuple<double, double, std::vector<double>, std::vector<double>,
        std::vector<double>, std::vector<double>>
        runDecisionTreeClassification(const std::string& filePath, int trainingRatio);

private:
    int min_samples_split;
    int max_depth;
    int n_feats;
    Node* root;

    Node* growTree(std::vector<std::vector<double>>& X, std::vector<double>& y, int depth = 0);
    double informationGain(std::vector<double>& y, std::vector<double>& X_column, double split_thresh);
    double mostCommonlLabel(std::vector<double>& y);
    double traverseTree(std::vector<double>& x, Node* node);

};

#endif  // DECISION_TREE_CLASSIFICATION_H


