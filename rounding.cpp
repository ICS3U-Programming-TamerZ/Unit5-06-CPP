// Copyright (c) 2022 Tamer Zreg All rights reserved.
//
// Created by: Tamer Zreg
// Created on: Dec. 08, 2022
// This program asks the user to enter a decimal
// number and the number of decimal places they would
// like to round. It then rounds the number to the
// number of specified decimal places.

#include <iostream>
#include <cmath>


// this function rounds the user number to the
// correct amount of decimal places
void roundDecimal(float &decNum, int &decPlaces) {
    // process for rounding number
    decNum = decNum * (pow(10, decPlaces));
    decNum += 0.5;
    decNum = static_cast<int>(decNum);
    decNum = decNum / (pow(10, decPlaces));
}

// gets input from user, catches invalid data,
// and displays results to console
int main() {
    // displays opening message
    std::cout << "This program rounds a decimal to the number of " \
                 "decimal places entered.";
    std::cout << std::endl;
    std::cout << std::endl;

    // declaring variables
    std::string decNumString, decPlacesString;
    float decNumFloat;
    int decPlacesInt;

    // get input from the user
    std::cout << "Enter a decimal number: ";
    std::cin >> decNumString;

    // checks if the user has entered the correct number
    try {
        // convert the user's input to a float
        decNumFloat = std::stof(decNumString);

        // get input from the user
        std::cout << "Enter the number of decimal places: ";
        std::cin >> decPlacesString;

        // checks if the user has entered the correct number
        try {
            // convert the user's input to an int
            decPlacesInt = std::stoi(decPlacesString);

            // checks if a negative number was entered
            if (decPlacesInt < 0) {
                std::cout << decPlacesInt << " is not a positive integer.";
            } else {
                // calls function round number
                roundDecimal(decNumFloat, decPlacesInt);

                // displays results to the user
                std::cout << std::endl;
                std::cout << decNumString << " rounded to " << decPlacesInt;
                std::cout << " decimals is " << decNumFloat;
            }
        // catches invalid strings
        } catch (std::invalid_argument) {
        // tells user did the input is not a number
        std::cout << "Invalid input!";
        }

    // catches invalid data
    } catch (std::invalid_argument) {
    // tells user did the input is not a number
    std::cout << decNumString<< " is not a decimal number.";
    }
}
