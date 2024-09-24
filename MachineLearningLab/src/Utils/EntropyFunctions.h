#ifndef ENTROPY_FUNCTIONS_H
#define ENTROPY_FUNCTIONS_H

#include <vector>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <Eigen/SVD>


                                    /// EntropyFunctions class definition ///

class EntropyFunctions {
public:
    static double entropy(const std::vector<double>& y);
    static double entropy(const std::vector<double>& y, const std::vector<int>& idxs);

};

#endif  // ENTROPY_FUNCTIONS_H


