#ifndef DATAPREPROCESSOR_H
#define DATAPREPROCESSOR_H

#include <vector>
#include <string>


class DataPreprocessor {

public:
    static void splitDataset(const std::vector<std::vector<double>>& dataset, double trainRatio,
        std::vector<std::vector<double>>& trainData, std::vector<double>& trainLabels,
        std::vector<std::vector<double>>& testData, std::vector<double>& testLabels);
    static void normalizeDataset(std::vector<std::vector<double>>& dataset);
    static void scaleDataset(std::vector<std::vector<double>>& dataset);
    double safeStod(const std::string& str, double default_val = 0.0);

};

#endif // DATAPREPROCESSOR_H
#pragma once





