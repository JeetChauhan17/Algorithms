#include <iostream>
#include <string>
#include <vector>
using namespace std;

string railFenceEncrypt(const string& text, int rails) {
    if (rails <= 1) return text;
    vector<string> fence(rails);
    int dir = 1, rail = 0;
    for (char ch : text) {
        fence[rail] += ch;
        rail += dir;
        if (rail == 0 || rail == rails - 1) dir = -dir;
    }
    string result;
    for (auto& row : fence) result += row;
    return result;
}

string railFenceDecrypt(const string& cipher, int rails) {
    if (rails <= 1) return cipher;
    vector<int> len(rails, 0);
    int dir = 1, rail = 0;
    for (size_t i = 0; i < cipher.length(); i++) {
        len[rail]++;
        rail += dir;
        if (rail == 0 || rail == rails - 1) dir = -dir;
    }

    vector<string> fence(rails);
    int idx = 0;
    for (int r = 0; r < rails; r++) {
        fence[r] = cipher.substr(idx, len[r]);
        idx += len[r];
    }

    string result;
    rail = 0; dir = 1;
    vector<int> pos(rails, 0);
    for (size_t i = 0; i < cipher.length(); i++) {
        result += fence[rail][pos[rail]++];
        rail += dir;
        if (rail == 0 || rail == rails - 1) dir = -dir;
    }
    return result;
}
