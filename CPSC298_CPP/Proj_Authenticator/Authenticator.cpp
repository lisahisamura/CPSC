/// @file Authenticator.cpp
/// @brief Compares authenticator code and message code to see if they match, then characterizes the message code.
/// @author Lisa Hisamura hisamura@chapman.edu
#include <iostream>
#include <string>
using namespace std;

int main() {

    const char k_cAuthenticatorCodeCharacter1 = 'E'; 
    const char k_cAuthenticatorCodeCharacter2 = 'C'; 
    const char k_cAuthenticatorCodeCharacter3 = 'A';
    const string authenticatorCodeString = "ECA";

    char messageCodeCharacter1;
    char messageCodeCharacter2;
    char messageCodeCharacter3;

    string messageCodeString = "";

    // PART I: Get user input for the message code
    // Concatenate characters into string variable

    cout << "Enter the first character of the message code: ";
    cin >> messageCodeCharacter1;
    messageCodeString += messageCodeCharacter1;

    cout << "Enter the second character of the message code: ";
    cin >> messageCodeCharacter2;
    messageCodeString += messageCodeCharacter2;

    cout << "Enter the third character of the message code: ";
    cin >> messageCodeCharacter3;
    messageCodeString += messageCodeCharacter3;

    cout << "Authenticator Code: " << authenticatorCodeString << endl;
    cout << "Message Code: " << messageCodeString << endl;

    // PART II: Character-by-Character Comparison

    int i;

    bool isAuthentic = true;
    for (i = 0; i < authenticatorCodeString.size(); ++i) {
        if (authenticatorCodeString.at(i) != messageCodeString.at(i)) {
            isAuthentic = false;
            break;
        }
    }

    if (isAuthentic) {
        cout << "Message is authentic." << endl;
    } else {
        cout << "Message is invalid." << endl;
    }


    // PART III: String comparison

    if (authenticatorCodeString == messageCodeString) {
        cout << "Concurrence: Message is authentic." << endl;
    } else {
        cout << "Concurrence: Message is invalid." << endl;
    }

    // PART IV: Characterize received message code
    
    const int k_iValidCodeChecksum = 5;
    int valueMessageCodeCharacter1 = int(messageCodeCharacter1);
    int valueMessageCodeCharacter2 = int(messageCodeCharacter2);
    int valueMessageCodeCharacter3 = int(messageCodeCharacter3);
        
    int checkSum = (valueMessageCodeCharacter1 + valueMessageCodeCharacter2 + valueMessageCodeCharacter3) % 7;
    int valueSum = (valueMessageCodeCharacter1 + valueMessageCodeCharacter2 + valueMessageCodeCharacter3);

    cout << "Characterization of Message Code" << endl;
    cout << "---------------------------------" << endl;
    cout << "ASCII values of Message Code Characters: " << valueMessageCodeCharacter1 << ", " << valueMessageCodeCharacter2 << ", " << valueMessageCodeCharacter3 << endl;
    cout << "Sum of ASCII values for Message Code Characters: "  << valueSum << endl;

    if (checkSum == k_iValidCodeChecksum) {
        cout << "Message Code Checksum  is valid: " << checkSum << endl;
    } else {
        cout << "Message Code Checksum is invalid: " << checkSum << "; expected: " << k_iValidCodeChecksum << endl;
    }

    if (!isAuthentic) {
        
        // Report which pairs of corresponding characters don't match
        if (messageCodeCharacter1 != k_cAuthenticatorCodeCharacter1) {
            cout << "First characters do not match: Message: " << messageCodeCharacter1 << "; Authenticator: " << k_cAuthenticatorCodeCharacter1 << endl;
        }
        if (messageCodeCharacter2 != k_cAuthenticatorCodeCharacter2) {
            cout << "Second characters do not match: Message: " << messageCodeCharacter2 << "; Authenticator: " << k_cAuthenticatorCodeCharacter2 << endl;
        }
        if (messageCodeCharacter3 != k_cAuthenticatorCodeCharacter3) {
            cout << "Third characters do not match: Message: " << messageCodeCharacter3 << "; Authenticator: " << k_cAuthenticatorCodeCharacter3 << endl;
        }

        // Lexicographical relationship
        bool isLexicographicallyLess;

        if (authenticatorCodeString > messageCodeString) {
            isLexicographicallyLess = true;
        } else if (authenticatorCodeString < messageCodeString) {
            isLexicographicallyLess = false;
        }

        if (isLexicographicallyLess) {
            cout << "Message code (" << messageCodeString << ") is lexicographically less than Authenticator code (" << authenticatorCodeString << ")" << endl;
        } else {
            cout << "Message code (" << messageCodeString << ") is lexicographically greater than Authenticator code (" << authenticatorCodeString << ")" << endl;
        }

    }
    
}

