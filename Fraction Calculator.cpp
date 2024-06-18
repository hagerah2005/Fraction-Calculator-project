/**
purpose:Our fraction calculator program is designed to simplify your mathematical computations with fractions
author1:merehan ibraheem elmotasem hassan fouad      email:merehan.ibraheem@gmail.com
author2:hagar ahmed mohamed                                             email:hagerah5162@gmail.com
author3:ayman ahmed abdelsamie                                        email:aabdelsame510@gmail.com

**/
#include<iostream>
#include<algorithm>
#include<string>
#include<regex>
using namespace std;

int main() {

    // Welcome message
    cout << "Welcome to the fraction calculator\n";
    long long a, b, c, d, numerator, denominator;
    char opr;
    string problem;

    //by using regex library
    regex input_regex("([+-]?\\d+)(?:\\/([+-]?\\d+))?\\s([\\+\\-\\*\\/]*)\\s([+-]?\\d+)(?:\\/([+-]?\\d+))?");
    while (true) {
        cout << "Please enter a rational number operation [num1 (+,-,*,/) num2] or exit: ";
        getline(cin, problem);

        // Verify the validity of the entry
        smatch match;
        if (problem == "exit") {
            cout << "Thank you for using the rational number calculator.\n";
            break;
        }
        if (!regex_match(problem, match, input_regex)) {
            cout << "Invalid operation. Try again.\n";
            continue;
        }


        // Parsing input
        if (match[2].str() == "") {
            // If the second fraction part is empty, it's an integer
            a = stoi(match[1]);
            b = 1;
        }
        else {
            a = stoi(match[1]);
            b = stoi(match[2]);
        }

        opr = match[3].str()[0];

        if (match[5].str() == "") {
            // If the fourth fraction part is empty, it's an integer
            c = stoi(match[4]);
            d = 1;
        }
        else {
            c = stoi(match[4]);
            d = stoi(match[5]);
        }

        //defensive programming
        if (b==0 || d==0){
            cout<<"diveded by zero not allowed , try again\n";
            continue;
        }

        // addition operations
        if (opr == '+') {
            numerator = a * d + c * b;
            denominator = b * d;
        }

        //devision operation
        else if (opr == '/') {
            if (c == 0) {
                cout << "Division by zero is not allowed! Please try again.\n";
                continue;
            }
            numerator = a * d;
            denominator = b * c;
        }

        //multiplication operation
        else if (opr == '-') {
            numerator = a * d - c * b;
            denominator = b * d;
        }

        //multiplication operation
        else if (opr == '*') {
            numerator = a * c;
            denominator = b * d;
        }
        else {
            cout << "Invalid operation. Try again.\n";
            continue;
        }

        // Simplify the output by using gcd
        long long gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (denominator == 1) {
            cout << "The result = " << numerator << endl;
        } else {
            cout << "The result = " << numerator << '/' << denominator << endl;
        }
    }

    return 0;
}


//fraction calculator algorithm link
//https://drive.google.com/file/d/1L8ZTRDl_v45IP64LxycIFGH45uSFN5N8/view?usp=sharing












