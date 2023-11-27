/*
C++ Programing
Author: John Winsor
Date: 2023-11-24
Filename: morseCode.cpp
Purpose: A program that converts English to Morse code and vice versa
Prgram title: Morse Code Converter
*/

#include "morseCodeFunctions.cpp"
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, string> morseCodeMap;
    initializeMorseCodeMap(morseCodeMap);

    cout << "MORSE CODE CONVERTER" << endl;
    cout << "Choose an option:\n";
    cout << "1. Encode English to Morse code\n";
    cout << "2. Decode Morse code to English\n";
    cout << "Enter option: ";
    int option;
    cin >> option;

    // Error handling for invalid input
    while (option != 1 && option != 2)
    {
        cout << "Invalid option. Please enter 1 or 2: ";
        cin >> option;
    }

    cout << "Enter the phrase from: \n";
    cout << "1. Keyboard\n";
    cout << "2. File\n";
    cout << "Enter option: ";
    int inputOption;
    cin >> inputOption;

    // Error handling for invalid input
    while (inputOption != 1 && inputOption != 2)
    {
        cout << "Invalid option. Please enter 1 or 2: ";
        cin >> inputOption;
    }

    cin.ignore(); // Ignore the newline character

    string phrase = getInput(inputOption == 2); // If inputOption is 2, then the input is from a file
    string converted;                           // The converted phrase

    // Encode or decode the phrase in if statement
    if (option == 1)
    {
        converted = encodeToMorse(phrase, morseCodeMap); // Encode the phrase
    }
    else
    {
        converted = decodeFromMorse(phrase, morseCodeMap); // Decode the phrase
    }

    cout << "Converted phrase: " << converted << "\n";
    writeOutput(phrase, converted);

    return 0;
}
