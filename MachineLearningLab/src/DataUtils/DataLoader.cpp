#include "DataLoader.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <wininet.h>
#include <stdexcept>
#include <fstream>
#include <regex>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <random>
#include "../DataUtils/DataPreprocessor.h"
#include <Windows.h> // For MessageBox
#include <string>     
using namespace System::Windows::Forms; // For MessageBox

//#pragma comment(lib, "wininet")

void DataLoader::loadAndPreprocessDataset(const std::string& file_path,
    std::vector<std::vector<double>>& dataset) {
    std::ifstream data_stream(file_path); // Open the file stream to read data from the file
    std::string data_string((std::istreambuf_iterator<char>(data_stream)),
        std::istreambuf_iterator<char>()); // Read the entire file into a string

    std::istringstream iss(data_string); // Create a string stream to read data line by line
    std::string line; // Variable to store each line of data
    DataPreprocessor preprocessor; // Instance of a data preprocessor class

    bool first_line = true; // Flag to indicate if it's the first line of data

    while (std::getline(iss, line)) { // Read each line from the string stream
        if (first_line) { // Skip the first line (header)
            first_line = false;
            continue;
        }
        std::stringstream ss(line); // Create a string stream to read data from each line
        std::string token; // Variable to store each token (data value) in the line
        std::vector<double> row; // Vector to store the values in a row (feature vector)

        int col_num = 1; // Counter for column number

        while (std::getline(ss, token, ',')) { // Read each token (data value) separated by commas
            if (col_num >= 2 && col_num <= 5) { // Check if the token belongs to columns 2, 3, 4, or 5 (feature vector)
                double value = preprocessor.safeStod(token); // Convert token to double using data preprocessor's safe_stod() function
                row.push_back(value); // Add the converted value to the feature vector row
            }
            else if (col_num == 6) { // The token belongs to column 6 (class label)
                if (token == "Iris-setosa") { // Check if the class label is "Iris-setosa"
                    row.push_back(1); // Add numerical value 1 to the feature vector row
                }
                else if (token == "Iris-versicolor") { // Check if the class label is "Iris-versicolor"
                    row.push_back(2); // Add numerical value 2 to the feature vector row
                }
                else if (token == "Iris-virginica") { // Check if the class label is "Iris-virginica"
                    row.push_back(3); // Add numerical value 3 to the feature vector row
                }
            }
            col_num++; // Increment the column number counter
        }
        dataset.push_back(row); // Add the feature vector row to the dataset (including X and y)
    }
}



//// Function to read and parse the dataset file, removing special characters
std::vector<std::vector<std::string>> DataLoader::readDatasetFromFilePath(const std::string& filePath)
{
    if (filePath.empty()) {
        MessageBox::Show("Please browse and select the dataset file from your PC.");
        return {}; // Return an empty vector since there's no valid file path
    }

    std::ifstream file(filePath);
    std::vector<std::vector<std::string>> data;

    if (!file.is_open()) {
        MessageBox::Show("Failed to open the dataset file: ");
        return {}; // Return an empty vector since file couldn't be opened
    }

    std::string line;

    while (std::getline(file, line))
    {

        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> row;

        while (std::getline(ss, token, ','))
        {
            // Remove double quotes from the token if present
            if (!token.empty() && token.front() == '"' && token.back() == '"')
            {
                token = token.substr(1, token.length() - 2);
            }

            row.push_back(token);
        }

        data.push_back(row);
    }

    file.close();

    if (data.empty()) {
        MessageBox::Show("The dataset file is empty or does not contain valid data.");
    }

    return data;
}


