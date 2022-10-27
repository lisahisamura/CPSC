#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include "Vector3D.h"


int main() {
    double const PI = 3.14159265;

    double Fx = 10.0 * cos(45 * PI/180.0); // Newtons
    double Fy = 10.0 * sin(45 * PI/180.0); // Newtons
    double Fz = 0;

    double Dx = 10.0; // Meters
    double Dy = 0.0; // Meters
    double Dz = 0.0; // Meters

    Vector3D vec3dForce(Fx, Fy, Fz);    // Newtons
    Vector3D vec3dDisplacement(Dx, Dy, Dz);

    vec3dForce.display();
    vec3dDisplacement.display();

    double dWork = vec3dForce.dot(vec3dDisplacement); // Jourles (= 1 Newton-meter)
    std::cout << "Work: " << dWork << std::endl;

    return 0;
}