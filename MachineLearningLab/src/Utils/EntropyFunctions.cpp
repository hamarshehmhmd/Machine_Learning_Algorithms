#include "EntropyFunctions.h"
#include <vector>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>


									// EntropyFunctions class implementation //



/// Calculates the entropy of a given set of labels "y".///
double EntropyFunctions::entropy(const std::vector<double>& y) {
	int total_samples = y.size();
	std::vector<double> hist;
	std::unordered_map<double, int> label_map;
	double entropy = 0.0;
	// Convert labels to unique integers and count their occurrences
	//TODO
	for (double label : y) {
		if (label_map.find(label) == label_map.end()) {
			label_map[label] = 1;
		}
		else {
			label_map[label]++;
		}
	}

	// Compute the probability and entropy
	//TODO
	for (auto pair : label_map) {
		double probability = 1.0 * pair.second / total_samples;
		double label_effect = probability * log2(probability);
		entropy = entropy - label_effect;
	}

	return entropy;
}


/// Calculates the entropy of a given set of labels "y" and the indices of the labels "idxs".///
double EntropyFunctions::entropy(const std::vector<double>& y, const std::vector<int>& idxs) {
	std::vector<double> hist;
	std::unordered_map<double, int> label_map;
	int total_samples = idxs.size();
	double entropy = 0.0;
	// Convert labels to unique integers and count their occurrences
	//TODO
	for (int index : idxs) {
		double label = y[index];

		if (label_map.find(label) == label_map.end()) {
			label_map[label] = 1;
		}
		else {
			label_map[label]++;
		}
	}

	// Compute the probability and entropy
	//TODO
	for (auto pair : label_map) {
		double probability = 1.0 * pair.second / total_samples;
		double label_effect = probability * log2(probability);
		entropy = entropy - label_effect;
	}

	return entropy;
}


