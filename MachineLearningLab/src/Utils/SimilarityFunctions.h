#ifndef SIMILARITYFUNCTIONS_H
#define SIMILARITYFUNCTIONS_H
#include <vector>

                        
                    /// SimilarityFunctions class definition ///

class SimilarityFunctions {
public:
    static double hammingDistance(const std::vector<double>& a, const std::vector<double>& b);
    static double jaccardDistance(const std::vector<double>& a, const std::vector<double>& b);
    static double cosineDistance(const std::vector<double>& a, const std::vector<double>& b);
    static double euclideanDistance(const std::vector<double>& a, const std::vector<double>& b);
    static double manhattanDistance(const std::vector<double>& a, const std::vector<double>& b);
    static double minkowskiDistance(const std::vector<double>& a, const std::vector<double>& b, int p);
};

#endif // SIMILARITYFUNCTIONS_H
