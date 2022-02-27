#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::string filename = "metrics_values.csv";
    std::ifstream input;

    input.open(filename);

    if(!input.is_open()){
        return 1;
    }

    while(input){
        std::string line;

        getline(input, line, ',');

        int kg;
        int lbs;
        int feet;
        int inches;

        std::cout << line << "--" << kg << std::endl;
        std::cout << line << "--" << lbs << std::endl;
        std::cout << line << "--" << feet << std::endl;
        std::cout << line << "--" << inches << std::endl;
    }

    input.close();

    return 0;

}
