/// @file leibnitz_pi_converge.cpp
/// @brief Uses the Leibnitz formula to approximate the value of pi (value of n increases).
/// @author Lisa Hisamura hisamura@chapman.edu
#include <iostream>
#include <string>
#include <cmath>
#include <cfloat> 
#include <iomanip>
using namespace std;

int main() {
    
    int n;

    for (n = 2; n <= 1048576; n *= 2) {
        double pi = 0.0;
        for (int k = 0; k <= n; k++) {
            pi += ((pow(-1.0, k)) / (2.0 * k + 1.0)) * 4.0;
        } 
        
        cout << "PI: " << setprecision(DBL_DIG) << fixed << pi;
        cout << "; n: " << n << endl;
    }

}