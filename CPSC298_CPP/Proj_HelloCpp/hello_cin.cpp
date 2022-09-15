/// @file hello_cin.cpp
/// @brief OUtputs a string entered by the user to standard output.
/// @author Lisa Hisamura hisamura@chapman.edu
#include <iostream>
#include <string>
using namespace std;
int main() {
    string strMessage;
    cout << "Please type a single word message" << endl;
    cin >> strMessage;
    cout << "Message: " << strMessage << endl;
    return 0;
}