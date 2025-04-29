#include <iostream>
#include <string>
using namespace std;

string vernamEncryptDecrypt(const string& text, const string& key) {
    string res = text;
    for (size_t i = 0; i < text.length(); i++) {
        res[i] = text[i] ^ key[i % key.length()];
    }
    return res;
}
