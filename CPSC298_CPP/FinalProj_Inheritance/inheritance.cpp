/// @file inheritance.cpp
/// @brief Two classes (rectangle and circle) that derive from a base class called Shape.
/// with functions to scale the shape object, compute its area, compute its perimeter, and display its properties.
/// @author Lisa Hisamura hisamura@chapman.edu
#include <iostream>
#include <string>
#include <cmath>

class Shape {

public:
	Shape(double dWidth, double dHeight);
	virtual ~Shape();
    virtual void scale(double dScaleFactor) = 0;
	virtual double area() = 0; // Pure virtual member function - no implementation in base class
	virtual double perimeter() = 0;
    virtual void displayProperties();

protected:
	double m_dWidth;
	double m_dHeight;
	std::string m_strType;
};

Shape::Shape(double dWidth, double dHeight) : m_dWidth(dWidth), m_dHeight(dHeight), m_strType("Shape")
{

}

Shape::~Shape()
{
    std::cout << "Shape Destructor called" << std::endl;
}

void Shape::displayProperties()
{
    std::cout << "Shape Type: " << this->m_strType << ", Height: " << this->m_dWidth << ", Width: " << this->m_dHeight << std::endl;
	return;
}


class Rectangle : public Shape
{
    public:
        Rectangle(double dWidth, double dHeight);
        virtual ~Rectangle();
        void scale(double dScaleFactor);
        double area();
        double perimeter();
};

Rectangle::Rectangle(double dWidth, double dHeight) : Shape(dWidth, dHeight)
{
	this->m_strType = "Rectangle";
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle Destructor called" << std::endl;
}

double Rectangle::area()
{
    return (this->m_dWidth * this->m_dHeight);
}

double Rectangle::perimeter()
{
    return (this->m_dWidth * 2 + this->m_dHeight * 2);
}

void Rectangle::scale(double scaleFactor)
{
    this->m_dWidth *= scaleFactor;
    this->m_dHeight *= scaleFactor;
}




class Circle: public Shape
{
    public:
        Circle(double dWidth, double dHeight);
        virtual ~Circle();
        void scale (double dScaleFactor);
        double area();
        double perimeter();
};

Circle::Circle(double dWidth, double dHeight) : Shape(dWidth, dHeight)
{
	this->m_strType = "Circle";
}

Circle::~Circle()
{
	std::cout << "Circle Destructor called" << std::endl;
}


double Circle::area()
{
	return ((M_PI * (this->m_dHeight * this->m_dHeight))/4);
}

double Circle::perimeter()
{
    return (this->m_dHeight * M_PI);
}

void Circle::scale(double scaleFactor)
{
    this->m_dWidth *= scaleFactor;
    this->m_dHeight *= scaleFactor;
}


int main()
{
    Rectangle* p_shapeRectangle = new Rectangle (2.0, 3.0);
    Circle* p_shapeCircle = new Circle (2.0, 2.0);

    Shape* p_shapes[2];

    p_shapes[0] = p_shapeCircle;
    p_shapes[1] = p_shapeRectangle;

    for (int i = 0; i < 2; i++) {
        // display properties of the shape using displayProperties
        p_shapes[i]->displayProperties();
        // compute area of the shape and print out using std::cout
        double dArea = p_shapes[i]->area();
        // compute perimeter of the shape and print out using std::cout
        double dPerimeter = p_shapes[i]->perimeter();
        // print area and perimeter of shape
        std::cout << "Area: " << dArea << ", Perimeter: " << dPerimeter << std::endl;
        // scale shape by a factor of 2
        p_shapes[i]->scale(2);
        // display properties of the shape again
        p_shapes[i]->displayProperties();
        // compute area of the shape again
        dArea = p_shapes[i]->area();
        // compute perimeter of the shape again
        dPerimeter = p_shapes[i]->perimeter();
        // print area and perimeter again
        std::cout << "Area: " << dArea << ", Perimeter: " << dPerimeter << std::endl;

        // (first circle, then rectangle)
    }

    // deallocate shape objects
    delete p_shapeCircle;
	delete p_shapeRectangle;

    return 0;
}
