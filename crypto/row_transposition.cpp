#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string rowTranspositionEncrypt(const string& ptext, const string& key) {
    int n = key.length();
    vector<string> rows(n, "");
    for (size_t i = 0; i < ptext.length(); i++) {
        rows[i % n] += ptext[i];
    }
    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());

    string result = "";
    for (char c : sortedKey) {
        int idx = key.find(c);
        result += rows[idx];
    }
    return result;
}
