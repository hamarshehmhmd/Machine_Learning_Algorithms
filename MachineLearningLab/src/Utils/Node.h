#ifndef NODE_H
#define NODE_H
#include "../DataUtils/DataLoader.h"
#include "../Evaluation/Metrics.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
#include <unordered_set>


                                // Node class definition //

class Node {
public:
    int feature;
    double threshold;
    Node* left;
    Node* right;
    double value;

    Node(int feature = 0, double threshold = 0.0, Node* left = nullptr, Node* right = nullptr, double value = -1.0);
    bool isLeafNode();

};


#endif // NODE_H