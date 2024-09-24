#ifndef FUZZY_C_MEANS_H
#define FUZZY_C_MEANS_H
#include "../DataUtils/DataLoader.h"
#include "../Evaluation/Metrics.h"
#include <string>
#include <vector>
#include <utility>
#include <limits>


                                        ///  FuzzyCMeans class definition  ///

class FuzzyCMeans {
public:
    FuzzyCMeans(int numClusters, int maxIterations, double fuzziness);

    void fit(const std::vector<std::vector<double>>& data);
    std::vector<int> predict(const std::vector<std::vector<double>>& data) const;
    std::tuple<double, double, std::vector<int>, std::vector<std::vector<double>>>
        runFuzzyCMeans(const std::string& filePath);

private:
    int numClusters_;
    int maxIterations_;
    double fuzziness_;

    std::vector<std::vector<double>> centroids_;
    std::vector<std::vector<double>> membershipMatrix_;

    void initializeMembershipMatrix(int numDataPoints);
    void updateMembershipMatrix(const std::vector<std::vector<double>>& data, const std::vector<std::vector<double>> centroids_);
    std::vector<std::vector<double>> updateCentroids(const std::vector<std::vector<double>>& data);

};

#endif  // FUZZY_C_MEANS_H

