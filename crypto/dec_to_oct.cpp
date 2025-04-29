#include <iostream>
#include <string>
using namespace std;

string decimalToOctal(int num) {
    string res = "";
    do {
        res = char('0' + num % 8) + res;
        num /= 8;
    } while (num > 0);
    return res;
}

int octalToDecimal(const string& octal) {
    int res = 0;
    for (char c : octal) {
        res = res * 8 + (c - '0');
    }
    return res;
}

string octalToHexadecimal(const string& octal) {
    int decimal = octalToDecimal(octal);
    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";
    do {
        hex = hexDigits[decimal % 16] + hex;
        decimal /= 16;
    } while (decimal > 0);
    return hex;
}
