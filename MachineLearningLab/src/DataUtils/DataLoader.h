#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <msclr\marshal_cppstd.h>
#include <Windows.h>
#include <Wininet.h>


class DataLoader {
public:
    static void loadAndPreprocessDataset(const std::string& file_path, std::vector<std::vector<double>>& dataset);
    static std::vector<std::vector<std::string>> DataLoader::readDatasetFromFilePath(const std::string& filePath);

  
};

#endif // DATALOADER_H


