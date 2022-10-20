/// @file ultimatemachine.cpp.cpp
/// @brief 
/// @author Lisa Hisamura hisamura@chapman.edu

#include <iostream>
#include <string>
// using namespace std;

class CUltimateMachine {
    
    public:

        // constructor
        CUltimateMachine() : m_bState(false)
        {
            std::cout << "CUltimateMachine constructor (ctor) called" << std::endl;
        }

        // deconstructor
        ~CUltimateMachine()
        {
            std::cout << "CUltimateMachine deconstructor (dtor) called" << std::endl;
        }

        // makes state of system 'observable'
        void displayState()
        {
            switch (m_bState) {
                case true:
                    std::cout << "Ultimate Machine is ON" << std::endl;
                    break;
                case false:
                    std::cout << "Ultimate Machine is OFF" << std::endl;
                    break;
            }
        }

        // the only function - turning on the switch
        void turnOn()
        {
            m_bState = true;
            displayState();
            if (true == m_bState)
            {
                m_bState = false;
            }
            displayState();
        }
    
    private:
        bool m_bState; // true (ON), false (OFF)


};


int main() {
    std::cout << "The Ultimate Machine Simulation" << std::endl;

    CUltimateMachine ultmach; // Declare an instance of the class
    ultmach.displayState();    // Display
    ultmach.turnOn();　// Turn the Ultimate Machine on
}