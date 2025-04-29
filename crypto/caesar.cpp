#include <iostream>
#include <string>
using namespace std;

string caesarEncrypt(const string& text, int key) {
    string result = "";
    key = key % 26;
    for (char ch : text) {
        if (isupper(ch))
            result += (ch - 'A' + key + 26) % 26 + 'A';
        else if (islower(ch))
            result += (ch - 'a' + key + 26) % 26 + 'a';
        else
            result += ch;
    }
    return result;
}

string caesarDecrypt(const string& text, int key) {
    return caesarEncrypt(text, -key);
}
