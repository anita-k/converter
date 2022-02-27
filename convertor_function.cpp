#include <iostream>
#include <string>
#include "log_function.cpp"
#include "timestamps.cpp"

void start();

std::string getConversionChoice();

void performConversion(std::string const &conversionChoice);

void performLengthConversion();

void performWeightConversion();

void ask_for_exit();

void start() {
    std::string conversionChoice = getConversionChoice();
    performConversion(conversionChoice);
    ask_for_exit();
}

std::string getConversionChoice() {
    std::string conversionChoice;
    std::cout << "Choose conversion type \n 1: cm to inches \n 2: kg to lbs \n";
    if (std::getline(std::cin >> std::ws, conversionChoice)) {
        return conversionChoice;
    }
    return "";
}

void performConversion(std::string const &conversionChoice) {

    if (conversionChoice == "1" || conversionChoice == "cm to inches" || conversionChoice == "CM TO INCHES") {
        performLengthConversion();
    } else if (conversionChoice == "2" || conversionChoice == "kg to lbs" || conversionChoice == "KG TO LBS") {
        performWeightConversion();
    } else {
        std::cout << "Error: You have entered an incorrect value." << std::endl;
    }

}

float roundoff(float value, unsigned char prec) {
    float pow_10 = pow(10.0f, (float) prec);
    return round(value * pow_10) / pow_10;
}

std::string roundOffString(float value, unsigned char prec) {
    float number = roundoff(value, prec);
    std::string num_text = std::to_string(number);
    std::string rounded = num_text.substr(0, num_text.find(".") + 3);
    return rounded;
}


void performLengthConversion() {
    float inch, cen;
    int feet;
    std::cout << "Enter the value in centimeters: ";
    std::cin >> cen;
    inch = cen / 2.54f;
    feet = static_cast<int>(inch / 12);
    inch = inch - static_cast<float>(feet * 12);

    std::string resultText =
            roundOffString(cen, 3) + " centimeters are equal to " + roundOffString(feet, 3) + " feet " +
            std::to_string(inch) + " inch(es).";
    std::string resultWithTimestamp = timestamp() + " " + resultText;
    write_log_file(resultWithTimestamp);

    std::cout << resultWithTimestamp << std::endl;
}

void performWeightConversion() {
    float kg, lbs;
    std::cout << "Enter the value in kilograms: ";
    std::cin >> kg;
    lbs = kg / 2.20462f;
    lbs = roundoff(lbs, 3);
    std::string resultText = roundOffString(kg, 3) + " kilograms are equal to " + roundOffString(lbs, 3) + " pounds.";
    std::string resultWithTimestamp = timestamp() + " " + resultText;
    write_log_file(resultWithTimestamp);

    std::cout << resultWithTimestamp << std::endl;
}

void ask_for_exit() {
    char YesNo;
    std::cout << "Do you want to continue? (Y or N) \n";
    std::cin >> YesNo;

    if (YesNo == 'N' || YesNo == 'n') {
        //do nothing, just quit
    } else {
        start();
    }
}

