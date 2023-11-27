// Purpose: This file contains the functions for the English to Morse code program.
//          The functions are:
//          - initializeMorseCodeMap: Initializes the Morse code map
//          - getInput: Gets the input from the user or file
//          - writeOutput: Writes the original and converted phrase to a file
//          - encodeToMorse: Encodes a phrase to Morse code

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

void initializeMorseCodeMap(map<char, string> &morseCodeMap);
string getInput(bool fromFile);
void writeOutput(const string &original, const string &converted);
string encodeToMorse(const string &phrase, map<char, string> &morseCodeMap);
string decodeFromMorse(const string &phrase, map<char, string> &morseCodeMap);


// Function to initialize the Morse code map
void initializeMorseCodeMap(map<char, string> &morseCodeMap)
{
    // Morse code map from https://en.wikipedia.org/wiki/Morse_code
    morseCodeMap['a'] = ".-";
    morseCodeMap['A'] = ".-";
    morseCodeMap['b'] = "-...";
    morseCodeMap['B'] = "-...";
    morseCodeMap['c'] = "-.-.";
    morseCodeMap['C'] = "-.-.";
    morseCodeMap['d'] = "-..";
    morseCodeMap['D'] = "-..";
    morseCodeMap['e'] = ".";
    morseCodeMap['E'] = ".";
    morseCodeMap['f'] = "..-.";
    morseCodeMap['F'] = "..-.";
    morseCodeMap['g'] = "--.";
    morseCodeMap['G'] = "--.";
    morseCodeMap['h'] = "....";
    morseCodeMap['H'] = "....";
    morseCodeMap['i'] = "..";
    morseCodeMap['I'] = "..";
    morseCodeMap['j'] = ".---";
    morseCodeMap['J'] = ".---";
    morseCodeMap['k'] = "-.-";
    morseCodeMap['K'] = "-.-";
    morseCodeMap['l'] = ".-..";
    morseCodeMap['L'] = ".-..";
    morseCodeMap['m'] = "--";
    morseCodeMap['M'] = "--";
    morseCodeMap['n'] = "-.";
    morseCodeMap['N'] = "-.";
    morseCodeMap['o'] = "---";
    morseCodeMap['O'] = "---";
    morseCodeMap['p'] = ".--.";
    morseCodeMap['P'] = ".--.";
    morseCodeMap['q'] = "--.-";
    morseCodeMap['Q'] = "--.-";
    morseCodeMap['r'] = ".-.";
    morseCodeMap['R'] = ".-.";
    morseCodeMap['s'] = "...";
    morseCodeMap['S'] = "...";
    morseCodeMap['t'] = "-";
    morseCodeMap['T'] = "-";
    morseCodeMap['u'] = "..-";
    morseCodeMap['U'] = "..-";
    morseCodeMap['v'] = "...-";
    morseCodeMap['V'] = "...-";
    morseCodeMap['w'] = ".--";
    morseCodeMap['W'] = ".--";
    morseCodeMap['x'] = "-..-";
    morseCodeMap['X'] = "-..-";
    morseCodeMap['y'] = "-.--";
    morseCodeMap['Y'] = "-.--";
    morseCodeMap['z'] = "--..";
    morseCodeMap['Z'] = "--..";
    morseCodeMap[' '] = "/";
}

// Function to get the input from the user or file
string getInput(bool fromFile)
{
    string input;

    if (fromFile)
    {
        ifstream inputFile("input.txt"); // Open the file

        if (inputFile.is_open())
        {
            getline(inputFile, input); // Get the input from the file
        }
        else
        {
            cout << "Error opening file 'input.txt'!\n";
        }
    }
    else
    {
        cout << "Enter the phrase to convert: ";
        getline(cin, input);
    }

    return input;
}

// Function to write the original and converted phrase to a file
void writeOutput(const string &original, const string &converted)
{
    ofstream outputFile("output.txt", ios::app);
    outputFile << "Original: " << original << "\nConverted: " << converted << "\n";
    outputFile.close();
}

/*****************************/
/*CONVERSIONS FOR MORSE CODE*/
/*****************************/

// Function to encode a phrase to Morse code
string encodeToMorse(const string &phrase, map<char, string> &morseCodeMap)
{
    stringstream ss;      // String stream to store the encoded phrase
    for (char c : phrase) // Iterate through the phrase
    {
        ss << morseCodeMap[c] << " "; // Add the Morse code for the letter to the string stream
    }

    return string(ss.str()); // Return the encoded phrase
}

// Function to decode a phrase from Morse code
string decodeFromMorse(const string &phrase, map<char, string> &morseCodeMap)
{
    stringstream ss;                      // String stream to store the decoded phrase
    stringstream morseCodeStream(phrase); // String stream to read the Morse code phrase
    string morseCode;                     // The Morse code for a letter

    while (getline(morseCodeStream, morseCode, ' ')) //
    {
        for (auto &it : morseCodeMap) // Iterate through the map
        {
            if (it.second == morseCode)
            {
                ss << it.first; // Add the letter to the string stream
                break;
            }
        }
    }

    return string(ss.str()); // Return the decoded phrase
}