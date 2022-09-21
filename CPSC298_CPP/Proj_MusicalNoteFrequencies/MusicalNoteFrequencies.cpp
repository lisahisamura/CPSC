/// @file MusicalNoteFrequencies.cpp
/// @brief Calculates the frequency and wavelength of musical notes.
/// @author Lisa Hisamura hisamura@chapman.edu
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//function to find k
int findk (string musicalNote) {
    int k;
    
    if (musicalNote == "C") {
        k = 0;
    } else if ((musicalNote == "C#") || (musicalNote == "Db")) {
        k = 1;
    } else if (musicalNote == "D") {
        k = 2;
    } else if ((musicalNote == "D#") || (musicalNote == "Eb")) {
        k = 3;
    } else if (musicalNote == "E") {
        k = 4;
    } else if (musicalNote == "F") {
        k = 5;
    } else if ((musicalNote == "F#") || (musicalNote == "Gb")) {
        k = 6;
    } else if (musicalNote == "G") {
        k = 7;
    } else if ((musicalNote == "G#") || (musicalNote == "Ab")) {
        k = 8;
    } else if (musicalNote == "A") {
        k = 9;
    } else if ((musicalNote == "A#") || (musicalNote == "Bb")) {
        k = 10;
    } else if (musicalNote == "B") {
        k = 11;
    }

    return k;
}


// function to calculate the frequency of a musical note
double CalcNoteFrequency(string musicalNote, int v, int k) {
    
    /* The constant variables below were not used at all in the program yet are included
    because they were specified in the project instructions. */ 
    const double dTwelfthRootOfTwo = 1.059463094359;
    const double referenceFrequency = 16.35; //C0

    const int twoRaisedToPowerOne = pow(2,1); //2^1
    const int twoRaisedToPowerTwo = pow(2,2); //2^2
    const int twoRaisedToPowerThree = pow(2,3); //2^3

    double frequency;
    double wavelengthInMeters;

    // formula
    frequency = referenceFrequency * pow(2, v) * pow(dTwelfthRootOfTwo, k);

    return frequency;
}


// function to calculate the wavelength of a musical note
double CalcNoteWavelength(double frequency) {
    const double speedOfSound = 345;

    //formula 
    double wavelength = speedOfSound/frequency;
}

int main() {
    string musicalNote;
    int v;

    cout << "What is the musical note?: ";
    cin >> musicalNote;
    cout << "What octave number?: ";
    cin >> v;

    int k = findk(musicalNote);

    double frequencyAnswer = CalcNoteFrequency(musicalNote, v, k);
    double wavelengthAnswerInCentimeters = CalcNoteWavelength(frequencyAnswer) * 100;

    // output
    cout << "Reference Frequency: 16.35Hz" << endl;
    cout << "Speed of Sound: 345 m/s" << endl;

    cout << "Note: " << musicalNote << v << "; nu: " << v << "; k: " << k << "; frequency: " << frequencyAnswer << " Hz; wavelength: " << wavelengthAnswerInCentimeters << " cm" << endl;

    return 0;
}