# Catalog
## Polynomial Reconstruction Using Lagrange Interpolation
This project demonstrates how to reconstruct a polynomial's constant term using Lagrange interpolation from data provided in a JSON format. The code reads data from a JSON string, decodes values from different numerical bases, and then computes the polynomial's constant term.

# Step-by-Step Process
## 1. Decode Values from JSON:

Function: decode_value
Purpose: Converts a given value from a specified base to a decimal integer.
Details:
Iterates through the value string from right to left.
Converts each character to its decimal equivalent based on the given base.
Accumulates the result to obtain the decimal representation.


## 2. Perform Lagrange Interpolation:

Function: lagrange_interpolation
Purpose: Computes the Lagrange polynomial coefficients based on the given x and y values.
Details:
Iterates through each point and computes the polynomial's coefficients.
Uses the Lagrange basis polynomials to construct the polynomial.



##  3. Find the Constant Term:

Function: find_constant_term
Purpose: Extracts the constant term (c) from the computed polynomial coefficients.
Details:
The constant term is the first coefficient in the list of polynomial coefficients.



##  4. Main Program Execution:

Function: main
Purpose: Parses the JSON input, extracts and decodes the values, performs Lagrange interpolation, and prints the constant term.
Details:
Parses JSON input to extract n, k, and data points.
Decodes each value from its respective base.
Computes polynomial coefficients and prints the constant term.



# Code Explanation
##  1. Include Libraries:

#include <iostream>: For input and output operations.
#include <vector>: For using the std::vector container.
#include <cmath>: For mathematical functions (though not used in this version).
#include <string>: For string manipulation.
#include <sstream>: For string stream operations.
#include <nlohmann/json.hpp>: For JSON parsing.


##  2. Function Definitions:

decode_value(const string& value, int base): Converts a string value from a specified base to decimal.
lagrange_interpolation(const vector<double>& x_values, const vector<double>& y_values): Calculates polynomial coefficients using Lagrange interpolation.
find_constant_term(const vector<double>& coefficients): Retrieves the constant term from the polynomial coefficients.


## 3. Main Function:

Parses a JSON string to extract data points.
Converts values from different bases to decimal.
Computes polynomial coefficients and prints the constant term.


JSON Input Format

keys: Contains the total number of data points (n) and the number of points required for interpolation (k).
1, 2, ..., n: Each key represents a data point with:
base: Numerical base of the value.
value: The value in the specified base.

Example JSON Input
{
    "keys": {
        "n": 4,
        "k": 3
    },
    "1": {
        "base": "10",
        "value": "4"
    },
    "2": {
        "base": "2",
        "value": "111"
    },
    "3": {
        "base": "10",
        "value": "12"
    },
    "6": {
        "base": "4",
        "value": "213"
    }
}



Compilation and Execution
Compile the Code:
g++ -o polynomial_reconstruction polynomial_reconstruction.cpp -std=c++11


Run the Program:
./polynomial_reconstruction


Enter JSON Input:
When prompted, paste the JSON input string and press Enter.



### Notes
Ensure the nlohmann/json.hpp header file is included in your project directory or properly linked.
Adjust the JSON input as needed to fit your data requirements.
