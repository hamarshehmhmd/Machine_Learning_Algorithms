#include "DecisionTreeRegression.h"
#include "../DataUtils/DataLoader.h"
#include "../Evaluation/Metrics.h"
#include "../DataUtils/DataPreprocessor.h"
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <set>
#include <numeric>
#include <unordered_set>
using namespace System::Windows::Forms; // For MessageBox



///  DecisionTreeRegression class implementation  ///
// Constructor for DecisionTreeRegression class.//
DecisionTreeRegression::DecisionTreeRegression(int min_samples_split, int max_depth, int n_feats)
	: min_samples_split(min_samples_split), max_depth(max_depth), n_feats(n_feats), root(nullptr)
{
}


// fit function:Fits a decision tree regression model to the given data.//
void DecisionTreeRegression::fit(std::vector<std::vector<double>>& X, std::vector<double>& y) {
	n_feats = (n_feats == 0) ? X[0].size() : min(n_feats, static_cast<int>(X[0].size()));
	root = growTree(X, y);
}


// predict function:Traverses the decision tree and returns the predicted value for a given input vector.//
std::vector<double> DecisionTreeRegression::predict(std::vector<std::vector<double>>& X) {

	std::vector<double> predictions;

	// Implement the function
	// TODO
	for (std::vector<double>& data_point : X) {
		//Traverse through tree with each given vector
		//TraverseTree returns label for given vector
		predictions.push_back(traverseTree(data_point, root));
	}

	return predictions;
}


// growTree function: Grows a decision tree regression model using the given data and parameters //
Node* DecisionTreeRegression::growTree(std::vector<std::vector<double>>& X, std::vector<double>& y, int depth) {

	int split_idx = -1;
	double split_thresh = 0.0;
	double best_mse = DBL_MAX;
	/* Implement the following:
		--- define stopping criteria
		--- Loop through candidate features and potential split thresholds.
		--- Find the best split threshold for the current feature.
		--- grow the children that result from the split
	*/
	bool same_label_check = true;
	//compare if the first label if it is same in the entire subset
	for (int i = 1; i < y.size(); i++) {
		//try to find the moment label is not the same and make same_label_check false ensure the stopping criteria is not true and break from loop
		if (y[i] != y[0]) {
			same_label_check = false;
			break;
		}
	}
	if (depth >= max_depth || X.size() <= min_samples_split || same_label_check || X.size() != y.size() || X.size() == 0 || y.size() == 0) {
		//create a leaf node and assign it most common label
		double predicted_mean = DecisionTreeRegression::mean(y);
		Node* node = new Node(NULL, NULL, NULL, NULL, predicted_mean);
		return node;
	}
	for (int feature = 0; feature < n_feats; feature++) {
		std::vector<double> X_column;
		for (int i = 0; i < X.size(); i++) {
			X_column.push_back(X[i][feature]);
		}
		for (auto threshold : X_column) {

			double mse = DecisionTreeRegression::meanSquaredError(y, X_column, threshold);

			//update the values
			if (mse < best_mse) {
				best_mse = mse;
				split_idx = feature;
				split_thresh = threshold;
			}
		}
	}
	//if no split then create leaf node.
	if (split_idx == -1) {
		double predicted_mean = DecisionTreeRegression::mean(y);
		Node* node = new Node(NULL, NULL, NULL, NULL, predicted_mean);
		return node;
	}
	//split data based on the best feature and threshold (split datasets)
	std::vector<double> y_right, y_left;
	std::vector<std::vector<double>> left_subset, right_subset;
	for (int i = 0; i < y.size(); i++) {
		if (split_thresh >= X[i][split_idx]) {
			y_left.push_back(y[i]);
			left_subset.push_back(X[i]);
		}
		else {
			y_right.push_back(y[i]);
			right_subset.push_back(X[i]);
		}
	}

	// TODO
	Node* left; // grow the left tree
	Node* right;  // grow the right tree
	//grow the tree recursively

	left = growTree(left_subset, y_left, depth + 1);
	right = growTree(right_subset, y_right, depth + 1);
	return new Node(split_idx, split_thresh, left, right); // return a new node with the split index, split threshold, left tree, and right tree
}


/// meanSquaredError function: Calculates the mean squared error for a given split threshold.
double DecisionTreeRegression::meanSquaredError(std::vector<double>& y, std::vector<double>& X_column, double split_thresh) {

	double mse = 0.0;
	// Calculate the mse
	// TODO
	std::vector<double> y_left, y_right;
	//Loop throguh all data points
	//if value in x_column is less then split thresh then y value then added into y_left else y_right
	for (int i = 0; i < y.size(); i++) {
		if (X_column[i] <= split_thresh) {
			y_left.push_back(y[i]);
		}
		else {
			y_right.push_back(y[i]);
		}
	}

	//calculate the mean of the y_left and y_right
	double mean_left = DecisionTreeRegression::mean(y_left);
	double mean_right = DecisionTreeRegression::mean(y_right);
	double mse_left = 0.0;

	//loop thourough y_left values and calculate mse
	for (double value : y_left) {
		double diff = value - mean_left;
		mse_left = mse_left + diff * diff;
	}
	//look if the y_left is not empty then finish its calculiatons of mse
	if (!y_left.empty()) {
		mse_left = mse_left / y_left.size();
	}

	double mse_right = 0.0;
	//loop through y_right values and calculate the mse.
	for (double value : y_right) {
		double diff = value - mean_right;
		mse_right = mse_right + diff * diff;
	}

	//look if the y_right is not empty then then finish the calculation of mse for the right subset
	if (!y_right.empty()) {
		mse_right = mse_right / y_right.size();
	}
	//here we calculate the overall mse which is like the weighted average of mses of the two groups based on their sizes
	mse = (y_left.size() * mse_left + y_right.size() * mse_right) / (y_left.size() + y_right.size());

	return mse;
}

// mean function: Calculates the mean of a given vector of doubles.//
double DecisionTreeRegression::mean(std::vector<double>& values) {

	double meanValue = 0.0;
	double sum = 0.0;

	for (auto value : values) {
		sum = sum + value;
	}

	meanValue = (sum / (values.size() * 1.0));
	// calculate the mean
	// TODO
	return meanValue;
}

// traverseTree function: Traverses the decision tree and returns the predicted value for the given input vector.//
double DecisionTreeRegression::traverseTree(std::vector<double>& x, Node* node) {

	/* Implement the following:
		--- If the node is a leaf node, return its value
		--- If the feature value of the input vector is less than or equal to the node's threshold, traverse the left subtree
		--- Otherwise, traverse the right subtree
	*/
	// TODO
	//check if node is leaf node if so return value for this node.
	if (node->isLeafNode()) {
		return node->value;
	}

	int feature = node->feature;
	int threshold = node->threshold;
	//check if feature value of input vector is less or equal to the nodes threshold then traverse the left tree else traverse the right
	if (x[feature] <= threshold) {
		return traverseTree(x, node->left);
	}
	else {
		return traverseTree(x, node->right);
	}

	//return 0.0;
}


/// runDecisionTreeRegression: this function runs the Decision Tree Regression algorithm on the given dataset and 
/// then returns a tuple containing the evaluation metrics for the training and test sets, 
/// as well as the labels and predictions for the training and test sets.

std::tuple<double, double, double, double, double, double,
	std::vector<double>, std::vector<double>,
	std::vector<double>, std::vector<double>>
	DecisionTreeRegression::runDecisionTreeRegression(const std::string& filePath, int trainingRatio) {
	try {
		// Check if the file path is empty
		if (filePath.empty()) {
			MessageBox::Show("Please browse and select the dataset file from your PC.");
			return {}; // Return an empty vector since there's no valid file path
		}

		// Attempt to open the file
		std::ifstream file(filePath);
		if (!file.is_open()) {
			MessageBox::Show("Failed to open the dataset file");
			return {}; // Return an empty vector since file couldn't be opened
		}
		// Load the dataset from the file path
		std::vector<std::vector<std::string>> data = DataLoader::readDatasetFromFilePath(filePath);

		// Convert the dataset from strings to doubles
		std::vector<std::vector<double>> dataset;
		bool isFirstRow = true; // Flag to identify the first row

		for (const auto& row : data) {
			if (isFirstRow) {
				isFirstRow = false;
				continue; // Skip the first row (header)
			}

			std::vector<double> convertedRow;
			for (const auto& cell : row) {
				try {
					double value = std::stod(cell);
					convertedRow.push_back(value);
				}
				catch (const std::exception& e) {
					// Handle the exception or set a default value
					std::cerr << "Error converting value: " << cell << std::endl;
					// You can choose to set a default value or handle the error as needed
				}
			}
			dataset.push_back(convertedRow);
		}

		// Split the dataset into training and test sets (e.g., 80% for training, 20% for testing)
		double trainRatio = trainingRatio * 0.01;

		std::vector<std::vector<double>> trainData;
		std::vector<double> trainLabels;
		std::vector<std::vector<double>> testData;
		std::vector<double> testLabels;

		DataPreprocessor::splitDataset(dataset, trainRatio, trainData, trainLabels, testData, testLabels);

		// Fit the model to the training data
		fit(trainData, trainLabels);

		// Make predictions on the test data
		std::vector<double> testPredictions = predict(testData);

		// Calculate evaluation metrics (e.g., MAE, MSE)
		double test_mae = Metrics::meanAbsoluteError(testLabels, testPredictions);
		double test_rmse = Metrics::rootMeanSquaredError(testLabels, testPredictions);
		double test_rsquared = Metrics::rSquared(testLabels, testPredictions);

		// Make predictions on the training data
		std::vector<double> trainPredictions = predict(trainData);

		// Calculate evaluation metrics for training data
		double train_mae = Metrics::meanAbsoluteError(trainLabels, trainPredictions);
		double train_rmse = Metrics::rootMeanSquaredError(trainLabels, trainPredictions);
		double train_rsquared = Metrics::rSquared(trainLabels, trainPredictions);

		MessageBox::Show("Run completed");
		return std::make_tuple(test_mae, test_rmse, test_rsquared,
			train_mae, train_rmse, train_rsquared,
			std::move(trainLabels), std::move(trainPredictions),
			std::move(testLabels), std::move(testPredictions));
	}
	catch (const std::exception& e) {
		// Handle the exception
		MessageBox::Show("Not Working");
		std::cerr << "Exception occurred: " << e.what() << std::endl;
		return std::make_tuple(0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
			std::vector<double>(), std::vector<double>(),
			std::vector<double>(), std::vector<double>());
	}
}

