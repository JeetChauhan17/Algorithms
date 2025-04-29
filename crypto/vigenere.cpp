#include <iostream>
#include <string>
using namespace std;

string vigenereEncrypt(const string& text, const string& key) {
    string result = "";
    int keyLen = key.length();
    for (size_t i = 0; i < text.length(); i++) {
        char ch = text[i];
        char k = tolower(key[i % keyLen]) - 'a';
        if (isupper(ch))
            result += (ch - 'A' + k + 26) % 26 + 'A';
        else if (islower(ch))
            result += (ch - 'a' + k + 26) % 26 + 'a';
        else
            result += ch;
    }
    return result;
}

string vigenereDecrypt(const string& text, const string& key) {
    string result = "";
    int keyLen = key.length();
    for (size_t i = 0; i < text.length(); i++) {
        char ch = text[i];
        char k = tolower(key[i % keyLen]) - 'a';
        if (isupper(ch))
            result += (ch - 'A' - k + 26) % 26 + 'A';
        else if (islower(ch))
            result += (ch - 'a' - k + 26) % 26 + 'a';
        else
            result += ch;
    }
    return result;
}
