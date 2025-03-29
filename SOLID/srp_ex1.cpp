/*
Single Responsibility Principle 

A class should have only one reason to change (one responsibility)

Why SRP?

Easier to modify file handling without affecting data processing.

Better for unit testing (each class has a single responsibility).

Ex: Separating File Handling & Data Processing
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


/*
A class handling both file operations and data processing is not a good design
*/
// class FileProcessor {
// public:
//     void readFile(const std::string& filename) {
//         std::ifstream file(filename);
//         std::string line;
//         while (std::getline(file, line)) {
//             m_data.push_back(line);
//         }
//     }

//     void processData() {
//         for (auto &line : m_data) {
//             std::cout << "Processing: " << line << std::endl;
//         }
//     }

// private:
//     std::vector<std::string> m_data;
// };

//So how about we can split into 2 classes?
class FileReader {
public:
    std::vector<std::string> readFile(const std::string& filename) {
        std::vector<std::string> data;
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            data.push_back(line);
        }
        return data;
    }
};

class DataProcessor {
public:
    void processData(const std::vector<std::string>& data) {
        for (auto& line : data) {
            std::cout << "Processing: " << line << std::endl;
        }
    }
};


int main() {
    /*
    bad approach
    FileProcessor badProcessor;
    badProcessor.readFile("data.txt");
    badProcessor.processData();
    */

    //Good approach (follows SRP)
    FileReader reader;
    DataProcessor processor;
    auto data = reader.readFile("data.txt");
    processor.processData(data);

    return 0;
}
