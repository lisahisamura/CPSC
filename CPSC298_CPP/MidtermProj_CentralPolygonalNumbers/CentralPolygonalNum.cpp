/// @file CentralPolygonalNum.cpp
/// @brief Computes the first N entries in the Lazy Caterer's Sequence,
/// then stores in an allocated array of integers within the class and saves to a file.
/// @author Lisa Hisamura hisamura@chapman.edu
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CentralPolygonalNumbers
{
    public:
        CentralPolygonalNumbers();
        CentralPolygonalNumbers(int nMax);
        ~CentralPolygonalNumbers();
        void display();
        bool save(std::string strFilename);

    private:
        int m_nMax;
        int* mp_iNumbers;
        int n;
};

// default constructor
CentralPolygonalNumbers::CentralPolygonalNumbers()
{
    m_nMax = 0;
    mp_iNumbers = new int[m_nMax + 1];
    for (n = 0; n <= m_nMax; n++) {
        mp_iNumbers[n] = ((n * n) + n + 2)/2;
    }
}

// overloaded constructor
CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax)
{
    m_nMax = nMax;
    mp_iNumbers = new int[nMax + 1];
   
    for (int n = 0; n <= nMax; ++n) {
        mp_iNumbers[n] = ((n * n) + n + 2)/2;
        
    }

}

// destructor
CentralPolygonalNumbers::~CentralPolygonalNumbers()
{
    
    delete[] mp_iNumbers;
    std::cout << "~CentralPolygonalNumbers called" << std::endl;
}

void CentralPolygonalNumbers::display()
{
    
    for (int n = 0; n <= m_nMax; ++n) {
        
        std::cout << "n: " << n << ", maximum number of pieces: " << mp_iNumbers[n] << endl;
    }
}

bool CentralPolygonalNumbers::save(std::string strFilename)
{
    std::ofstream ofsNumbers;

    for (n = 0; n <= m_nMax; n++) {
        ofsNumbers << mp_iNumbers[n] << endl;
        ofsNumbers.close();
    }

    return 0;

}


int main()
{
    
    CentralPolygonalNumbers cpn(10);
    cpn.display();
    cpn.save("CPN");
}