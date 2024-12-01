/* Jal Maru Extra Credit Lab EECS 348 */
// 20 points for quiz and exam section
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
double extractNumeric(const string & input) {
    //initialize all values needed
    bool hasDigits = false;
    bool hasDecimalPoint = false;
    bool hasSign = false;
    double result = 0.0;
    double decimalFactor = 1;
    int i = 0;
    //check for sign at beginning of string input
    if (input[i] == '+' || input[i] == '-') {
        hasSign = true;
        i++;
    }
    //process rest
    for (; i < input.length(); ++i) {
        if (input[i] >= '0' && input[i] <= '9') { //check if it is valid digit, then update result accordingly
            hasDigits = true;
            if (hasDecimalPoint) {
                decimalFactor *= 0.1; //multiply decimal factor by 0.1 to add new digit to number correctly
                result += (input[i] - '0') * decimalFactor;
            } else {
                result = result * 10 + (input[i] - '0'); //if no decimal, multiply result by 10 and add new digit
            }
        } else if (input[i] == '.' && !hasDecimalPoint) {
            hasDecimalPoint = true; //update bool to true to adjust decimalFactor for later digits
        } else {
            //not a number, sign, or decimal point; invalid
            return -999999.99;
        }
    }
    //no digits or only sign errors taken care of
    if (!hasDigits || (hasSign && input.length() == 1)) {
        return -999999.99;
    }
    //return number or -999999.99, sign if included
    return (input[0] == '-') ? (-1*result) : result;  //if - sign in first position of input, return negative result
}

int main() {
    string input;
    while (true) {
        cout << "Enter a number (or type 'END' to exit): ";
        cin >> input;
        //end program
        if (input == "END") {
            break;
        }
        //output section
        double number = extractNumeric(input);
        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}
