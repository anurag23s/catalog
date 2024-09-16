// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <string>
// #include <sstream>
// #include <nlohmann/json.hpp>

// using Json = nlohmann::json;
// using namespace std;

// // Function to decode a value from a given base to decimal
// int decode_value(const string& value, int base) {
//     int decimal_value = 0;
//     int power = 1;
//     for (int i = value.size() - 1; i >= 0; --i) {
//         char digit = value[i];
//         int digit_value = (digit >= '0' && digit <= '9') ? (digit - '0') : (digit - 'a' + 10);
//         decimal_value += digit_value * power;
//         power *= base;
//     }
//     return decimal_value;
// }

// // Function to perform Lagrange Interpolation
// vector<double> lagrange_interpolation(const vector<double>& x_values, const vector<double>& y_values) {
//     int n = x_values.size();
//     vector<double> coefficients(n, 0);

//     for (int i = 0; i < n; ++i) {
//         vector<double> term(n, 0);
//         term[0] = 1.0;

//         for (int j = 0; j < n; ++j) {
//             if (i != j) {
//                 vector<double> new_term(n, 0);
//                 new_term[0] = -x_values[j];
//                 for (int k = 1; k < n; ++k) {
//                     new_term[k] = -x_values[j] * term[k] + term[k - 1];
//                 }
//                 for (int k = 0; k < n; ++k) {
//                     term[k] = term[k] / (x_values[i] - x_values[j]);
//                 }
//                 for (int k = 0; k < n; ++k) {
//                     term[k] *= new_term[k];
//                 }
//             }
//         }

//         for (int j = 0; j < n; ++j) {
//             coefficients[j] += y_values[i] * term[j];
//         }
//     }

//     return coefficients;
// }

// // Function to find the constant term (c) from the coefficients
// double find_constant_term(const vector<double>& coefficients) {
//     return coefficients[0];
// }

// int main() {
//     string json_str = R"({
//         "keys": 4,
//         "roots": [
//             {"base": "10", "value": "111", "key": "1"},
//             {"base": "12", "value": "213", "key": "2"},
//             {"base": "2", "value": "111", "key": "2"}
//         ]
//         })";

//     // Parse the JSON string
//     Json root = Json::parse(json_str);

//     vector<double> x_values;
//     vector<double> y_values;

//     const Json& roots = root["roots"];
//     for (const auto& r : roots) {
//     // Convert base and key from string to integer
//     int base = std::stoi(r["base"].get<string>());
//     int x = std::stoi(r["key"].get<string>());
//     string value = r["value"].get<string>();
//     int y = decode_value(value, base);

//     x_values.push_back(static_cast<double>(x));
//     y_values.push_back(static_cast<double>(y));
// }

//     vector<double> coefficients = lagrange_interpolation(x_values, y_values);
//     double constant_term = find_constant_term(coefficients);

//     cout << "Constant Term (c): " << constant_term << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <nlohmann/json.hpp>

using Json = nlohmann::json;
using namespace std;

// Function to decode a value from a given base to decimal
int decode_value(const string& value, int base) {
    int decimal_value = 0;
    int power = 1;
    for (int i = value.size() - 1; i >= 0; --i) {
        char digit = value[i];
        int digit_value = (digit >= '0' && digit <= '9') ? (digit - '0') : (digit - 'a' + 10);
        decimal_value += digit_value * power;
        power *= base;
    }
    return decimal_value;
}

// Function to perform Lagrange Interpolation
vector<double> lagrange_interpolation(const vector<double>& x_values, const vector<double>& y_values) {
    int n = x_values.size();
    vector<double> coefficients(n, 0);

    for (int i = 0; i < n; ++i) {
        vector<double> term(n, 0);
        term[0] = 1.0;

        for (int j = 0; j < n; ++j) {
            if (i != j) {
                vector<double> new_term(n, 0);
                new_term[0] = -x_values[j];
                for (int k = 1; k < n; ++k) {
                    new_term[k] = -x_values[j] * term[k] + term[k - 1];
                }
                for (int k = 0; k < n; ++k) {
                    term[k] = term[k] / (x_values[i] - x_values[j]);
                }
                for (int k = 0; k < n; ++k) {
                    term[k] *= new_term[k];
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            coefficients[j] += y_values[i] * term[j];
        }
    }

    return coefficients;
}

// Function to find the constant term (c) from the coefficients
double find_constant_term(const vector<double>& coefficients) {
    return coefficients[0];
}

int main() {
    string json_str = R"({
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
    })";

    // Parse the JSON string
    Json root = Json::parse(json_str);

    vector<double> x_values;
    vector<double> y_values;

    // Extract the number of keys
    int num_keys = root["keys"]["n"];

    // Iterate through each key in the JSON
    for (int i = 1; i <= num_keys; ++i) {
        if (root.contains(to_string(i))) {
            const Json& entry = root[to_string(i)];
            int base = std::stoi(entry["base"].get<string>());
            int x = i; // Using the key as x value
            string value = entry["value"].get<string>();
            int y = decode_value(value, base);

            x_values.push_back(static_cast<double>(x));
            y_values.push_back(static_cast<double>(y));
        }
    }

    vector<double> coefficients = lagrange_interpolation(x_values, y_values);
    double constant_term = find_constant_term(coefficients);

    cout << "Constant Term (c): " << constant_term << endl;

    return 0;
}
