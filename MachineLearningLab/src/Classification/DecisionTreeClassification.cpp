#include "DecisionTreeClassification.h"
#include "../DataUtils/DataLoader.h"
#include "../Evaluation/Metrics.h"
#include "../Utils/EntropyFunctions.h"
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>
#include <fstream>
#include <sstream>
#include <map>
#include <random>
#include "../DataUtils/DataPreprocessor.h"
using namespace System::Windows::Forms; // For MessageBox

// DecisionTreeClassification class implementation //


// DecisionTreeClassification is a constructor for DecisionTree class.//
DecisionTreeClassification::DecisionTreeClassification(int min_samples_split, int max_depth, int n_feats)
	: min_samples_split(min_samples_split), max_depth(max_depth), n_feats(n_feats), root(nullptr) {}


// Fit is a function to fits a decision tree to the given data.//
void DecisionTreeClassification::fit(std::vector<std::vector<double>>& X, std::vector<double>& y) {
	n_feats = (n_feats == 0) ? X[0].size() : min(n_feats, static_cast<int>(X[0].size()));
	root = growTree(X, y);
}


// Predict is a function that Traverses the decision tree and returns the prediction for a given input vector.//
std::vector<double> DecisionTreeClassification::predict(std::vector<std::vector<double>>& X) {
	std::vector<double> predictions;

	// Implement the function
	// TODO
	//Go through each vector in given set
	for (std::vector<double>& data_point : X) {
		//Traverse through tree with each given vector
		//TraverseTree returns label for given vector
		predictions.push_back(traverseTree(data_point, root));
	}
	return predictions;
}


// growTree function: This function grows a decision tree using the given data and labelsand  return a pointer to the root node of the decision tree.//
Node* DecisionTreeClassification::growTree(std::vector<std::vector<double>>& X, std::vector<double>& y, int depth) {

	/* Implement the following:
		--- define stopping criteria
		--- Loop through candidate features and potential split thresholds.
		--- greedily select the best split according to information gain
		---grow the children that result from the split
	*/
	double best_gain = -1.0; // set the best gain to -1
	int n_label;

	int split_idx = -1; // split index
	double split_thresh = 0.0; // split threshold
	//samples and levels
	//define the stopping criterias for tree growth
	//assume same label is true and stop recursion
	bool same_label_check = true;
	//compare if the first label if it is same in the entire subset
	for (int i = 1; i < y.size(); i++) {
		//try to find the moment label is not the same and make same_label_check false ensure the stopping criteria is not true and break from loop
		if (y[i] != y[0]) {
			same_label_check = false;
			break;
		}
	}

	if (depth >= max_depth || X.size() <= min_samples_split || same_label_check) {
		//create a leaf node and assign it most common label
		double predicted_label = DecisionTreeClassification::mostCommonlLabel(y);
		Node* node = new Node(NULL, NULL, NULL, NULL, predicted_label);
		return node;
	}
	//double threshold;
	//loop through potential features and split thresholds

	for (int feature = 0; feature < n_feats; feature++) {

		std::vector<double> X_column;
		for (int i = 0; i < X.size(); i++) {

			X_column.push_back(X[i][feature]);
		}
		for (double threshold : X_column) {
			//calculate the informationgain for the split based on its threshold and feature
			double ig = DecisionTreeClassification::informationGain(y, X_column, threshold);
			//update the values
			if (ig > best_gain) {
				best_gain = ig;
				split_idx = feature;
				split_thresh = threshold;
			}
		}
	}
	//if no gain then create leaf node.
	if (split_idx == -1) {
		double predicted_label = DecisionTreeClassification::mostCommonlLabel(y);
		Node* node = new Node(NULL, NULL, NULL, NULL, predicted_label);
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


/// informationGain function: Calculates the information gain of a given split threshold for a given feature column.
double DecisionTreeClassification::informationGain(std::vector<double>& y, std::vector<double>& X_column, double split_thresh) {
	// parent loss // You need to caculate entropy using the EntropyFunctions class//
	double parent_entropy = EntropyFunctions::entropy(y);

	/* Implement the following:
	   --- generate split
	   --- compute the weighted avg. of the loss for the children
	   --- information gain is difference in loss before vs. after split
	*/
	double ig = 0.0;

	// TODO
	//split the data into two datasets
	std::vector<int> left_idx, right_idx;

	//loop through the data points and add into the datasets based on feature value is less than or equal to the split threshold
	for (int i = 0; i < y.size(); i++) {
		if (X_column[i] <= split_thresh) {
			left_idx.push_back(i);
		}
		else {
			right_idx.push_back(i);
		}
	}

	//calculate the entropy of the left and right childrens datasets 
	double leftchild_entropy = EntropyFunctions::entropy(y, left_idx);
	double rightchild_entropy = EntropyFunctions::entropy(y, right_idx);

	//calculate the weighted average of the children entropyies
	//the relative eight of right and left childeren compared to the parent dataset
	double left_weight = left_idx.size() / (y.size() * 1.0);
	double right_weight = right_idx.size() / (y.size() * 1.0);
	double average_child_entropy = left_weight * leftchild_entropy + right_weight * rightchild_entropy;

	//calculate the information gain basically the difference in loss before and after the split
	ig = parent_entropy - average_child_entropy;
	return ig;
}


// mostCommonlLabel function: Finds the most common label in a vector of labels.//
double DecisionTreeClassification::mostCommonlLabel(std::vector<double>& y) {
	double most_common = 0.0;

	// TODO
	//assume the first in the vector of labels, the first label is the most common label and store its count
	int common_count = 1;
	most_common = y[0];

	//go through the labels from the second element
	for (int i = 1; i < y.size(); i++) {
		double cur_label = y[i];
		int cur_count = 1;
		//count the amount of current label in the vector
		for (int j = i + 1; j < y.size(); j++) {
			if (y[j] == cur_label) {
				cur_count++;
			}
		}
		//replace the old values of most common and its count, with the new most common and new count.
		if (cur_count > common_count) {
			most_common = cur_label;
			common_count = cur_count;
		}
	}
	return most_common;
}


// traverseTree function: Traverses a decision tree given an input vector and a node.//
double DecisionTreeClassification::traverseTree(std::vector<double>& x, Node* node) {

	/* Implement the following:
		--- If the node is a leaf node, return its value
		--- If the feature value of the input vector is less than or equal to the node's threshold, traverse the left subtree
		--- Otherwise, traverse the right subtree
	*/
	// TODO
	// 
	//check if node is leafnode return value
	if (node->isLeafNode()) {
		return node->value;
	}
	//traverse left tree
	int feature = node->feature;
	double threshold = node->threshold;
	if (x[feature] <= threshold) {
		return traverseTree(x, node->left);
	}
	else {
		//traverse right tree
		return traverseTree(x, node->right);
	}

	//return 0.0;
}


/// runDecisionTreeClassification: this function runs the decision tree classification algorithm on the given dataset and 
/// then returns a tuple containing the evaluation metrics for the training and test sets, 
/// as well as the labels and predictions for the training and test sets.///
std::tuple<double, double, std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>>
DecisionTreeClassification::runDecisionTreeClassification(const std::string& filePath, int trainingRatio) {
	DataPreprocessor DataPreprocessor;
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

		std::vector<std::vector<double>> dataset; // Create an empty dataset vector
		DataLoader::loadAndPreprocessDataset(filePath, dataset);

		// Split the dataset into training and test sets (e.g., 80% for training, 20% for testing)
		double trainRatio = trainingRatio * 0.01;

		std::vector<std::vector<double>> trainData;
		std::vector<double> trainLabels;
		std::vector<std::vector<double>> testData;
		std::vector<double> testLabels;

		DataPreprocessor::splitDataset(dataset, trainRatio, trainData, trainLabels, testData, testLabels);

		// Fit the model to the training data
		fit(trainData, trainLabels);//

		// Make predictions on the test data
		std::vector<double> testPredictions = predict(testData);

		// Calculate accuracy using the true labels and predicted labels for the test data
		double test_accuracy = Metrics::accuracy(testLabels, testPredictions);


		// Make predictions on the training data
		std::vector<double> trainPredictions = predict(trainData);

		// Calculate accuracy using the true labels and predicted labels for the training data
		double train_accuracy = Metrics::accuracy(trainLabels, trainPredictions);

		MessageBox::Show("Run completed");
		return std::make_tuple(train_accuracy, test_accuracy,
			std::move(trainLabels), std::move(trainPredictions),
			std::move(testLabels), std::move(testPredictions));
	}
	catch (const std::exception& e) {
		// Handle the exception
		MessageBox::Show("Not Working");
		std::cerr << "Exception occurred: " << e.what() << std::endl;
		return std::make_tuple(0.0, 0.0, std::vector<double>(),
			std::vector<double>(), std::vector<double>(),
			std::vector<double>());
	}
}
