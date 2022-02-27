#include <string>
#include <iostream>
#include <iomanip>

void run_convertor_loop() {
    bool exit = false;
    char choice;
    std::string conversionChoice;

    while (!exit) {

        std::cout << "Choose conversion type \n 1: cm to inches \n 2: kg to lbs \n";
        std::getline(std::cin, conversionChoice);

        if (conversionChoice == "1" || conversionChoice == "cm to inches" || conversionChoice == "CM TO INCHES") {
            float inch, cen;
            int feet;
            std::cout << "Enter the value in centimeters: ";
            std::cin >> cen;
            inch = cen / 2.54;
            feet = inch / 12;
            inch = inch - feet * 12;

            std::cout << cen << " centimeters are equal to " << feet << " feet " << std::setprecision(3) << inch
                      << " inch(es)." << std::endl;


        } else if (conversionChoice == "2" || conversionChoice == "kg to lbs" || conversionChoice == "KG TO LBS") {
            float kg, lbs;
            std::cout << "Enter the value in kilograms: ";
            std::cin >> kg;
            lbs = kg / 2.20462;
            std::cout << kg << " kilograms are equal to " << std::setprecision(3) << lbs << " pounds." << std::endl;

        } else {
            std::cout << "Error: You have entered an incorrect value." << std::endl;

        }

        std::cout << "Do you want to continue? (Y or N) \n";
        std::cin >> choice;

        if (choice == 'N' || choice == 'n') {
            exit = true;
        }

    }

//    std::cin.get();

}
