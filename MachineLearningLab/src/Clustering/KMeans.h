#ifndef KMEANS_H
#define KMEANS_H

#include "../DataUtils/DataLoader.h"
#include "../Evaluation/Metrics.h"
#include <string>
#include <vector>
#include <utility>
#include <limits>

                                                    /// KMeans class definition ///


class KMeans {
public:
    KMeans(int numClusters, int maxIterations);
    void fit(const std::vector<std::vector<double>>& data);
    std::vector<int> predict(const std::vector<std::vector<double>>& data) const;
    std::tuple<double, double, std::vector<int>, std::vector<std::vector<double>>>
        runKMeans(const std::string& filePath);

private:
    int numClusters_;
    int maxIterations_;

    std::vector<std::vector<double>> centroids_;

};

#endif  // KMEANS_H




