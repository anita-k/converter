#include <iostream>
#include <fstream>

inline bool fileExists(const std::string& name) {
    struct stat buffer{};
    return (stat (name.c_str(), &buffer) == 0);
}

void write_log_file(std::string& logText) {

    std::string fileName = "logfile.txt";
    std::ofstream myLog;
    if (fileExists(fileName)){
        myLog.open(fileName, std::ios_base::app);
    } else {
        // Create and open a text file
        myLog.open(fileName);
    }

    // Write to the file
    myLog << logText << std::endl;

    // Close the file
    myLog.close();
}