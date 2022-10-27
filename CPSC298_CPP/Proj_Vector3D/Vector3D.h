#if !defined(VECTOR_3D_H)  
#define VECTOR_3D_H  // Sentinel

#include <vector>
#include <iostream>
#include <string>

class Vector3D
{
    public:
        Vector3D(); // Default Constructor
        Vector3D(double dX, double dY, double dZ); // Overloaded Constructor
        ~Vector3D(); // Destructor
        double dot(Vector3D vec3d); // Compute vector dot product
        void display(); // Display vector components to standard output
    
    private:
        std::vector<double>m_vector = {0, 0, 0};
};

#endif