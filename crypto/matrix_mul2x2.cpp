#include <iostream>
using namespace std;

void multiplyMatrix(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 2; j++) 
            C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j];
}
