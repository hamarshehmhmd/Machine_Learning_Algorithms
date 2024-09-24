#include "Node.h"

                                    // Node class implementation //

/// Node is a constructor for Node class.///
Node::Node(int feature, double threshold, Node* left, Node* right, double value)
    : feature(feature), threshold(threshold), left(left), right(right), value(value) {
}

///// isLeafNode is a function to check if the node is a leaf node.///
bool Node::isLeafNode() {
    return value != -1.0;
}
