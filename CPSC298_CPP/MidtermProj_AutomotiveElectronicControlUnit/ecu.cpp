// @file ecu.cpp
/// @brief Implementation file for ElectronicControlUnit class
/// @author hisamura@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream> // defines std::cout

class ElectronicControlUnit
{

public:
    ElectronicControlUnit();
    ~ElectronicControlUnit();
    void handleCommand(char cCommand); // accepts a character that corresponds to the button press

private:
    bool m_bActivatedHydraulicJacks; // button A
    bool m_bActivatedBeltTires;      // button B
    bool m_bActivatedIRIlluminate;   // button E
    void activateHydraulicJacks();    // for A - handles the deployment and retraction of the hydraulic jacks
    void activateBeltTires();           // for B - activates special "grid tire treads"
    void activateIRIlluminate();   // for E - activates infrared driving lights
};

// default constructor
ElectronicControlUnit::ElectronicControlUnit()
{
    m_bActivatedHydraulicJacks = 0;
    m_bActivatedBeltTires = 0;
    m_bActivatedIRIlluminate = 0;
}

// destructor
ElectronicControlUnit::~ElectronicControlUnit()
{

}


void ElectronicControlUnit::handleCommand (char cCommand)
{
    switch (cCommand)
    {
        case 'A':
        case 'a':
            activateHydraulicJacks();
            break;
        
        case 'B':
        case 'b':
            activateBeltTires();
            break;
        
        case 'E':
        case 'e':
            activateIRIlluminate();
            break;
            
        default:
            break;
    }
}

void ElectronicControlUnit::activateHydraulicJacks()
{
    if (!m_bActivatedHydraulicJacks) {
        if (!m_bActivatedBeltTires) {
            m_bActivatedHydraulicJacks = 1;
            std::cout << "Hydraulic Jacks activated" << std::endl;
        } else {
             m_bActivatedHydraulicJacks = 1;
            m_bActivatedBeltTires = 0;
            std::cout << "Hydraulic Jacks activated" << std::endl;
            std::cout << "Belt Tires deactivated" << std::endl;
        }
    } else {
        m_bActivatedHydraulicJacks = 0;
        std::cout << "Hydraulic Jacks deactivated" << std::endl;
    }
}

void ElectronicControlUnit::activateBeltTires()
{
    if (!m_bActivatedBeltTires && !m_bActivatedHydraulicJacks) {
        m_bActivatedBeltTires = 1;
        std::cout << "Belt Tires activated" << std::endl;
    } else if (!m_bActivatedBeltTires && m_bActivatedHydraulicJacks)
    {
        std::cout << "Hydraulic Jacks must first be deactivated" << std::endl;
    } else {
        m_bActivatedBeltTires = 0;
        std::cout << "Belt Tires deactivated" << std::endl;
    }
}

void ElectronicControlUnit::activateIRIlluminate()
{
    if (!m_bActivatedIRIlluminate) {
        m_bActivatedIRIlluminate = 1;
        std::cout << "Infrared Illumination activated" << std::endl;
    } else {
        m_bActivatedIRIlluminate = 0;
        std::cout << "Infrared Illumination deactivated" << std::endl;
    }
}


main ()
{

    ElectronicControlUnit electronicControlUnit;
    char cCommand = 'z';
    std::cout << "Press X to turn off ignition or enter a steering wheel button (A, B, or E)" << std::endl;

    

    while (cCommand != 'X' && cCommand != 'x') {
        
        std::cout << "       (A)" << std::endl;
        std::cout << "   (F) (G) (B)" << std::endl;
        std::cout << "   (E)     (C)" << std::endl;
        std::cout << "       (D)" << std::endl;

        std::cin >> cCommand;
        
        
        if (cCommand != 'X' && cCommand != 'x') {
            electronicControlUnit.handleCommand(cCommand);
            // std::cin >> cCommand;
        }
        
    }

    
}
