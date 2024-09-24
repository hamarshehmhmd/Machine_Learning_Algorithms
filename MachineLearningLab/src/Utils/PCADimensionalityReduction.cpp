#include "PCADimensionalityReduction.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <Eigen/SVD>
#include <algorithm>
#include <numeric>
#include <random>
#include <vcclr.h>

                                /// PCADimensionalityReduction class implementation ///


// calculate_mean: Function to calculate the mean of each feature //
std::vector<double> PCADimensionalityReduction::calculate_mean(const std::vector<std::vector<double>>& data)
{
	std::vector<double> mean(data[0].size(), 0.0);

	for (const auto& row : data) {
		for (size_t i = 0; i < row.size(); ++i) {
			mean[i] += row[i];
		}
	}

	for (double& value : mean) {
		value /= data.size();
	}

	return mean;
}


// calculate_covariance_matrix: Function to calculate the covariance matrix //
Eigen::MatrixXd PCADimensionalityReduction::calculate_covariance_matrix(const std::vector<std::vector<double>>&data, const std::vector<double>&mean) {

	const size_t num_features = data[0].size();
	const size_t num_samples = data.size();

	Eigen::MatrixXd covariance(num_features, num_features);

	for (size_t i = 0; i < num_features; ++i) {
		for (size_t j = 0; j < num_features; ++j) {
			double cov = 0.0;
			for (const auto& row : data) {
				cov += (row[i] - mean[i]) * (row[j] - mean[j]);
			}
			covariance(i, j) = cov / (num_samples - 1);
		}
	}

	return covariance;
}


// performPCA: Function to perform PCA on the dataset //
std::vector<std::vector<double>> PCADimensionalityReduction::performPCA(const std::vector<std::vector<double>>& data, int numDimensions) {
    // Convert the data into Eigen matrix for efficient computation
    Eigen::MatrixXd dataset(data.size(), data[0].size());
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j) {
            dataset(i, j) = data[i][j];
        }
    }

    // Compute the mean of each feature
    Eigen::VectorXd mean = dataset.colwise().mean();

    // Center the data by subtracting the mean
    Eigen::MatrixXd centeredData = dataset.rowwise() - mean.transpose();

    // Compute the covariance matrix
    Eigen::MatrixXd covariance = (centeredData.adjoint() * centeredData) / double(centeredData.rows() - 1);

    // Perform eigendecomposition of the covariance matrix
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(covariance);
    if (eigensolver.info() != Eigen::Success) {
        std::cerr << "Eigendecomposition failed." << std::endl;
        return {};
    }

    // Get the eigenvectors (principal components)
    Eigen::MatrixXd eigenvectors = eigensolver.eigenvectors();

    // Select the top k eigenvectors corresponding to the largest eigenvalues
    int numSamples = dataset.rows();
    int numFeatures = dataset.cols();
    int k = std::min(numDimensions, numFeatures);
    Eigen::MatrixXd projectionMatrix = eigenvectors.rightCols(k);

    // Project the data onto the lower-dimensional space
    Eigen::MatrixXd reducedData = centeredData * projectionMatrix;

    // Convert the reduced data back to std::vector<std::vector<double>>
    std::vector<std::vector<double>> reducedDataVector;
    reducedDataVector.reserve(numSamples);
    for (int i = 0; i < numSamples; ++i) {
        std::vector<double> sample;
        sample.reserve(k);
        for (int j = 0; j < k; ++j) {
            sample.push_back(reducedData(i, j));
        }
        reducedDataVector.push_back(sample);
    }

    // Return the reduced-dimensional data
    return reducedDataVector;
}


