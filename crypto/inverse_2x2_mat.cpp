#include <iostream>
using namespace std;

bool inverseMatrix2x2(int mat[2][2], int inv[2][2], int mod = 26) {
    int det = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) % mod;
    if (det < 0) det += mod;

    // Find modular inverse of determinant
    int detInv = -1;
    for (int i = 1; i < mod; i++) {
        if ((det * i) % mod == 1) {
            detInv = i;
            break;
        }
    }
    if (detInv == -1) return false; // No inverse exists

    inv[0][0] = (mat[1][1] * detInv) % mod;
    inv[0][1] = (-mat[0][1] * detInv + mod) % mod;
    inv[1][0] = (-mat[1][0] * detInv + mod) % mod;
    inv[1][1] = (mat[0][0] * detInv) % mod;
    return true;
}
