#include <iostream>
#include <string>
using namespace std;

// Key is a 26-letter string like "QWERTYUIOPASDFGHJKLZXCVBNM"
string monoalphabeticEncrypt(const string& ptext, const string& key) {
    string res = "";
    for (char ch : ptext) {
        if (isupper(ch))
            res += key[ch - 'A'];
        else if (islower(ch))
            res += tolower(key[ch - 'a']);
        else
            res += ch;
    }
    return res;
}

string monoalphabeticDecrypt(const string& ctext, const string& key) {
    string res = "";
    for (char ch : ctext) {
        if (isalpha(ch)) {
            bool upper = isupper(ch);
            char base = upper ? 'A' : 'a';
            char real = '?';
            for (int i = 0; i < 26; i++) {
                if (toupper(key[i]) == toupper(ch)) {
                    real = i + base;
                    break;
                }
            }
            res += real;
        } else {
            res += ch;
        }
    }
    return res;
}
