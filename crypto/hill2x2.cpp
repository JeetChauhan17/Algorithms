#include <iostream>
#include <string>
using namespace std;

string hillEncrypt(const string& ptext, int key[2][2]) {
    string res = "";
    string text = ptext;
    if (text.length() % 2 != 0) text += 'X'; // pad if odd
    for (size_t i = 0; i < text.length(); i += 2) {
        int x = text[i] - 'A';
        int y = text[i+1] - 'A';
        res += (char)((key[0][0]*x + key[0][1]*y) % 26 + 'A');
        res += (char)((key[1][0]*x + key[1][1]*y) % 26 + 'A');
    }
    return res;
}
