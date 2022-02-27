#include "convertor_loop.cpp"
#include "convertor_function.cpp"
#include<sstream>
#include <ostream>
#include <vector>

std::ostream &operator<<(std::ostream &os, const std::vector<float> &vector){
    std::string valueCount = std::to_string(vector.size());
    os << "values[" + valueCount + "]: ";
    bool first = true;
    for (auto v: vector) {
        if (!first) os << ", ";
        first = false;
        os << v;
    }
    os << ";" << std::endl;
    return os;
};

struct Measurements {
    std::string name;
    std::vector<float> values;

    friend std::ostream &operator<<(std::ostream &os, const std::vector<float> &vector);

    friend std::ostream &operator<<(std::ostream &os, const Measurements &measurements) {

        os << "name: " << measurements.name << "; ";
        os << measurements.values;

        return os;
    };

};

std::vector<Measurements> getMeasurementsFromFile(const std::string &fileName) {

    int lineCount = 0;
    //    std::vector<Measurements> measurementsTest = {
    //        Measurements("kg", {65,78,45,56,77,66,80,120,125}),
    //        Measurements("kg", {180,165,132,52,0,45,908,2,33}),
    //        Measurements("kg", {5.8,5.9,6.2,6.3,6.03,1,2,0,222}),
    //        Measurements("kg", {122,222,240,325,112,87,125,321,16}),
    //    };
    std::vector<Measurements> measurementsParsed{};

    if (fileExists(fileName)) {
        // Parse the file line by line
        std::ifstream file(fileName);
        std::string singleLine;
        while (std::getline(file, singleLine)) {
            //            std::cout << singleLine;
            Measurements measurement = {};
            measurement.values = {};

            // Parse the line word by word delimited by ","
            std::stringstream s_stream(singleLine); //create string stream from the line
            std::string element;
            int wordPosition = 0;
            while (std::getline(s_stream, element, ',')) {
                if (wordPosition == 0) {
                    measurement.name = element;
                } else {
                    float singleValue = std::stof(element);
                    measurement.values.push_back(singleValue);
                }
                //                std::cout << element;
                wordPosition += 1;
            }

            measurementsParsed.push_back(measurement);
            lineCount += 1;
        }
    } else {
        // Send error
        std::cout << "File is missing";
    }

    std::cout << "Line count: " << lineCount << std::endl;

    return measurementsParsed;
}

int main() {
//    First version with while loop:
//    run_convertor_loop();

//  Same functionality but in functional style:
    start();

//    TODO: csv parser is ready, need to loop through each value and convert it
//    std::string fileName = "metrics_values.csv";
//    std::vector<Measurements> measurements = getMeasurementsFromFile(fileName);
//    for (auto measurement: measurements) {
//        std::cout << measurement;
//    }
//        timestamp();

    return 0;
}
