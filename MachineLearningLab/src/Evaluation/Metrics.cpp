#include "Metrics.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include "../Utils/SimilarityFunctions.h"


												///  Metrics class implementation  ///
			

// 1. Regression evaluation metrics //

// meanAbsoluteError function: Calculates the mean absolute error between two vectors of values.//
double Metrics::meanAbsoluteError(const std::vector<double>& trueValues, const std::vector<double>& predictedValues) {
	if (trueValues.size() != predictedValues.size()) {
		throw std::runtime_error("Error: trueValues and predictedValues have different sizes.");
	}
	double mae = 0.0;
	double n = trueValues.size();
	for (int i = 0; i < n; i++) {
		mae += std::abs(trueValues[i] - predictedValues[i]);
	}
	return mae / n;
}


// rootMeanSquaredError function: Calculates the root mean squared error between two vectors of values.//
double Metrics::rootMeanSquaredError(const std::vector<double>& trueValues, const std::vector<double>& predictedValues) {
	if (trueValues.size() != predictedValues.size()) {
		throw std::runtime_error("Error: trueValues and predictedValues have different sizes.");
	}
	double rmse = 0.0;
	double n = trueValues.size();
	for (int i = 0; i < n; i++) {
		double diff = trueValues[i] - predictedValues[i];
		rmse += diff * diff;
	}
	return std::sqrt(rmse / n);
}


/// rSquared function: Calculates the R-squared value of a given set of true values and predicted values.//
double Metrics::rSquared(const std::vector<double>& trueValues, const std::vector<double>& predictedValues) {
	if (trueValues.size() != predictedValues.size()) {
		throw std::runtime_error("Error: trueValues and predictedValues have different sizes.");
	}
	double n = trueValues.size();
	double y_mean = 0.0;
	double SST = 0.0;
	double SSE = 0.0;

	// Calculate y_mean
	for (double y : trueValues) {
		y_mean += y;
	}
	y_mean /= n;

	// Calculate SST
	for (double y : trueValues) {
		SST += (y - y_mean) * (y - y_mean);
	}

	// Calculate SSE
	for (int i = 0; i < n; i++) {
		SSE += (trueValues[i] - predictedValues[i]) * (trueValues[i] - predictedValues[i]);
	}

	// Check for division by zero
	if (SST == 0.0) {
		throw std::runtime_error("Error: SST is zero.");
	}

	// Calculate R-squared
	double r_squared = 1.0 - (SSE / SST);
	return r_squared;
}



	// 2. Classification evaluation metrics //

	// accuracy function: Calculates the accuracy of the predicted labels compared to the true labels.//
	double Metrics::accuracy(const std::vector<double>&trueLabels, const std::vector<double>&predictedLabels) {
	if (trueLabels.size() == 0) {
		throw std::runtime_error("trueLabels vector is empty, division by zero.");
	}

	int correct = 0;
	for (size_t i = 0; i < trueLabels.size(); ++i) {
		if (trueLabels[i] == predictedLabels[i]) {
			correct++;
		}
	}
	return std::ceil(static_cast<double>(correct) / static_cast<double>(trueLabels.size()) * 100);
}


// precision function: Calculates the precision of a given class label from the true labels and predicted labels.//
double Metrics::precision(const std::vector<double>& trueLabels, const std::vector<double>& predictedLabels, int classLabel) {
	int truePositive = 0, falsePositive = 0;
	for (size_t i = 0; i < trueLabels.size(); ++i) {
		if (predictedLabels[i] == classLabel) {
			if (trueLabels[i] == classLabel) {
				truePositive++;
			}
			else {
				falsePositive++;
			}
		}
	}
	if (truePositive + falsePositive == 0) {
		return 0;
	}
	else {
		return static_cast<double>(truePositive) / (truePositive + falsePositive) * 100;
	}
}


// recall function: Calculates the recall of a given class label from the true labels and predicted labels.//
double Metrics::recall(const std::vector<double>& trueLabels, const std::vector<double>& predictedLabels, int classLabel) {
	int truePositive = 0, falseNegative = 0;
	for (size_t i = 0; i < trueLabels.size(); ++i) {
		if (trueLabels[i] == classLabel) {
			if (predictedLabels[i] == classLabel) {
				truePositive++;
			}
			else {
				falseNegative++;
			}
		}
	}
	if (truePositive + falseNegative == 0) {
		return 0;
	}
	else {
		return static_cast<double>(truePositive) / (truePositive + falseNegative) * 100;
	}
}


// f1Score function: Calculates the F1 score for a given class label.//
double Metrics::f1Score(const std::vector<double>& trueLabels, const std::vector<double>& predictedLabels, int classLabel) {
	double precisionVal = precision(trueLabels, predictedLabels, classLabel);
	double recallVal = recall(trueLabels, predictedLabels, classLabel);
	if (precisionVal + recallVal == 0) {
		return 0;
	}
	else {
		return 2 * (precisionVal * recallVal) / (precisionVal + recallVal);
	}
}


/// confusionMatrix function: Calculates the confusion matrix given true labels and predicted labels.
std::vector<std::vector<int>> Metrics::confusionMatrix(const std::vector<double>& trueLabels, const std::vector<double>& predictedLabels, const int numClasses) {
	std::vector<std::vector<int>> cm(numClasses, std::vector<int>(numClasses, 0));
	int n = trueLabels.size();

	for (int i = 0; i < n; i++) {
		int trueLabel = static_cast<int>(trueLabels[i]) - 1;
		int predictedLabel = static_cast<int>(predictedLabels[i]) - 1;

		// Perform error checking to ensure valid indices
		if (trueLabel >= 0 && trueLabel < numClasses && predictedLabel >= 0 && predictedLabel < numClasses) {
			cm[trueLabel][predictedLabel]++;
		}
		else {
			// Handle error case, e.g., throw an exception or print an error message
			throw std::runtime_error("Invalid labels encountered in trueLabels or predictedLabels vectors.");
		}
	}

	return cm;
}


// 3. Clustering evaluation metrics //

// calculateDaviesBouldinIndex function: Calculates the Davies-Bouldin index for a given set of data points and cluster labels.//
double Metrics::calculateDaviesBouldinIndex(const std::vector<std::vector<double>>& X, const std::vector<int>& labels) {
	int numClusters = *std::max_element(labels.begin(), labels.end()) + 1;
	std::vector<double> clusterSizes(numClusters, 0.0);
	std::vector<std::vector<double>> centroids(numClusters, std::vector<double>(X[0].size(), 0.0));

	// Calculate cluster sizes and centroids
	for (size_t i = 0; i < X.size(); ++i) {
		int cluster = labels[i];
		const std::vector<double>& point = X[i];

		for (size_t j = 0; j < point.size(); ++j) {
			centroids[cluster][j] += point[j];
		}

		clusterSizes[cluster] += 1.0;
	}

	// Calculate cluster centroids by dividing by cluster sizes
	for (int i = 0; i < numClusters; ++i) {
		if (clusterSizes[i] > 0.0) {
			for (size_t j = 0; j < centroids[i].size(); ++j) {
				centroids[i][j] /= clusterSizes[i];
			}
		}
	}

	std::vector<double> clusterDiameters(numClusters, 0.0);
	for (int i = 0; i < numClusters; ++i) {
		const std::vector<double>& centroid = centroids[i];

		double maxDistance = 0.0;
		for (size_t j = 0; j < X.size(); ++j) {
			if (labels[j] == i) {
				double distance = SimilarityFunctions::euclideanDistance(X[j], centroid);
				if (distance > maxDistance) {
					maxDistance = distance;
				}
			}
		}

		clusterDiameters[i] = maxDistance;
	}

	double daviesBouldinIndex = 0.0;
	for (int i = 0; i < numClusters; ++i) {
		double maxIndex = 0.0;

		for (int j = 0; j < numClusters; ++j) {
			if (i != j) {
				double index = (clusterDiameters[i] + clusterDiameters[j]) / SimilarityFunctions::euclideanDistance(centroids[i], centroids[j]);
				if (index > maxIndex) {
					maxIndex = index;
				}
			}
		}

		daviesBouldinIndex += maxIndex;
	}

	daviesBouldinIndex /= numClusters;
	return daviesBouldinIndex;
}


// calculateSilhouetteScore function: Calculates the Silhouette Score for a given set of data points and labels.//
double Metrics::calculateSilhouetteScore(const std::vector<std::vector<double>>& X, const std::vector<int>& labels) {
	int n = X.size();
	std::vector<double> clusterDistances(n, 0.0);
	std::vector<double> clusterSizes(n, 0.0);

	for (size_t i = 0; i < X.size(); ++i) {
		int cluster = labels[i];
		const std::vector<double>& point = X[i];

		for (size_t j = 0; j < X.size(); ++j) {
			if (i != j) {
				if (labels[j] == cluster) {
					clusterDistances[i] += SimilarityFunctions::euclideanDistance(point, X[j]);
					clusterSizes[i] += 1.0;
				}
			}
		}

		if (clusterSizes[i] > 0) {
			clusterDistances[i] /= clusterSizes[i];
		}
	}

	double silhouetteScore = 0.0;
	for (size_t i = 0; i < X.size(); ++i) {
		int cluster = labels[i];
		double a = clusterDistances[i];
		double b = std::numeric_limits<double>::max();

		for (size_t j = 0; j < X.size(); ++j) {
			if (labels[j] != cluster) {
				double distance = SimilarityFunctions::euclideanDistance(X[i], X[j]);
				if (distance < b) {
					b = distance;
				}
			}
		}

		double s = 0.0;
		if (a < b) {
			s = 1.0 - (a / b);
		}
		else if (a > b) {
			s = (b / a) - 1.0;
		}

		silhouetteScore += s;
	}

	silhouetteScore /= n;
	return silhouetteScore;
}



