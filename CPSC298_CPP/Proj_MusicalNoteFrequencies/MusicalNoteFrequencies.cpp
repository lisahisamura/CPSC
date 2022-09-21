/// @file MusicalNoteFrequencies.cpp
/// @brief Calculates the frequency and wavelength of musical notes.
/// @author Lisa Hisamura hisamura@chapman.edu
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//to find k
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

    // switch(musicalNote){
    //     case 'C':
    //         k = 0;
    //         break;
    //     case 'C#':
    //     case "Db":
    //         k = 1;
    //         break;
    //     case "D":
    //         k = 2;
    //         break;
    //     case "D#":
    //     case "Eb":
    //         k = 3;
    //         break;
    //     case "E":
    //         k = 4;
    //         break;
    //     case "F":
    //         k = 5;
    //         break;
    //     case "F#":
    //     case "Gb":
    //         k = 6;
    //         break;
    //     case "G":
    //     case "Ab":
    //         k = 7;
    //         break;
    //     case "G#":
    //         k = 8;
    //         break;
    //     case "A":
    //         k = 9;
    //         break;
    //     case "A#":
    //     case "Bb":
    //         k = 10;
    //         break;
    //     case "B":
    //         k = 11;
    //         break;
    //     default:
    //         break;
    // }

    return k;
}

double CalcNoteFrequency(string musicalNote, int v, int k) {
    const double dTwelfthRootOfTwo = 1.059463094359;
    const double referenceFrequency = 16.35; //C0

    const int twoRaisedToPowerOne = pow(2,1); //2^1
    const int twoRaisedToPowerTwo = pow(2,2); //2^2
    const int twoRaisedToPowerThree = pow(2,3); //2^3

    double frequency;
    double wavelengthInMeters;

    frequency = referenceFrequency * pow(2, v) * pow(dTwelfthRootOfTwo, k);

    return frequency;
}

double CalcNoteWavelength(double frequency) {
    const double speedOfSound = 345;

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


    cout << "Reference Frequency: 16.35Hz" << endl;
    cout << "Speed of Sound: 345 m/s" << endl;
    // cout << "Note: C0; nu: 0; k: 0; frequency: " << frequency << " Hz; wavelength: " << wavelength << " cm" << endl;
    // cout << "Note: C#0; nu: 0; k: 1; frequency: " << frequency << " Hz; wavelength: " << wavelength << " cm" << endl;
    // cout << "Note: D0; nu: 0; k: 2; frequency: " << frequency << " Hz; wavelength: " << wavelength << " cm" << endl;
    // cout << "Note: D3; nu: 3; k: 2; frequency: " << frequency << " Hz; wavelength: " << wavelength << " cm" << endl;
    // cout << "Note: C4; nu: 4; k: 0; frequency: " << frequency << " Hz; wavelength: " << wavelength << " cm" << endl;
    // cout << "Note: D#7; nu: 7; k: 3; frequency: " << frequency << " Hz; wavelength: " << wavelength << " cm" << endl;
    // cout << "Note: C8; nu: 8; k: 0; frequency: " << frequency << " Hz; wavelength: " << wavelengthInMeters * 100 << " cm" << endl;

    cout << "Note: " << musicalNote << v << "; nu: " << v << "; k: " << k << "; frequency: " << frequencyAnswer << " Hz; wavelength: " << wavelengthAnswerInCentimeters << " cm" << endl;

    return 0;
}