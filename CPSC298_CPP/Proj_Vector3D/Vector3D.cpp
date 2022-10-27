#include <vector>
#include <iostream>
#include <string>
#include "Vector3D.h"

Vector3D::Vector3D()
{
    this->m_vector.at(0) = 0.0;
    this->m_vector.at(1) = 0.0;
    this-> m_vector.at(2) = 0.0;
    return;
}

Vector3D::Vector3D(double dX, double dY, double dZ)
{
    this->m_vector.at(0) = dX;
    this->m_vector.at(1) = dY;
    this->m_vector.at(2) = dZ;
    return;
}

Vector3D::~Vector3D() { }

void Vector3D::display()
{
    std::cout << this->m_vector.at(0)<< " x, " << this->m_vector.at(0)<< " y, " << this->m_vector.at(0)<< " z " << std::endl;
    return;
}

double Vector3D::dot(Vector3D vec3d)
{
    double dDotProduct = 0.0;
    for (unsigned int i = 0; i < this -> m_vector.size(); i++)  // implements thru vector
    {
        dDotProduct += this->m_vector.at(i)* vec3d.m_vector.at(i); //aibi
    }

    return dDotProduct;
}