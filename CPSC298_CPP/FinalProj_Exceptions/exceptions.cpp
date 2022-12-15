/// @file exceptions.cpp
/// @brief Finds the sum of integers from 1 to n.
/// @author Lisa Hisamura hisamura@chapman.edu

#include <iostream>
#include <stdexcept>
#include <string>

// Sum the integers from 1 to n. For example, if n is 5, then
// sigma returns the sum 1 + 2 + 3 + 4 + 5 == 15.
// @param n unsigned integer upper bound of summation
// @pre n >= 1
// @post return value is the sum of the integers from 1 to n.
//  @return sum of the integers from 1 to n, where n is specified as an argument or 0 if an error occurred.

unsigned long sigma (unsigned long n)
{
    unsigned long sum = 0;

    try
    {
        // Check preconditions
        //     Raise a std::runtime_error exception if the precondition (n >= 1) is not met.
        if (n < 1) {
            throw std::runtime_error ("Precondition n>=1 violated; invalid value for argument n: "
            + std:: to_string(n) + " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")");
        }

        // Function body
        //     Implement a for loop to compute sum of integers from 1 to n
        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        
        // Check postconditions
        //     Raise a std::runtime_error exception if the postcondition (sum == (n(n+1)/2))
        //     is not met.
        if (sum != (n * (n + 1))/2)
        {
            throw std::runtime_error ("Postcondition (n(n+1))/2 violated; sum: "
            + std:: to_string(sum) + "; n(n+1)/2: " + std::to_string(n * (n + 1) / 2)
            + " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")");
        }

    }
    catch (std::runtime_error & ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
        std::cout << "Cannot compute sum; returning 0" << std::endl;
        sum = 0; // 0 is retturned to indicate an error occurred.
    }

    return sum;
}

int main()
{
    int sum = sigma(5);
    std::cout << "sigma(5) = " << sum << std::endl;
    sum = sigma(0);
    std::cout << "sigma(0) = " << sum << std::endl;

    return 0;
}