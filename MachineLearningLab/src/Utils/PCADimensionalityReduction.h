#ifndef PCA_DIMENSIONALITY_REDUCTION_H
#define PCA_DIMENSIONALITY_REDUCTION_H

#include <vector>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <Eigen/SVD>


                                    /// PCADimensionalityReduction class definition ///

class PCADimensionalityReduction {
public:
    std::vector<double> calculate_mean(const std::vector<std::vector<double>>& data);
    Eigen::MatrixXd calculate_covariance_matrix(const std::vector<std::vector<double>>& data, const std::vector<double>& mean);
    std::vector<std::vector<double>> performPCA(const std::vector<std::vector<double>>& data, int numDimensions);

};

#endif  // PCA_DIMENSIONALITY_REDUCTION_H
