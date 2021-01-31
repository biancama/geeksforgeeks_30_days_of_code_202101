//
// Created by Massimo Biancalani on 31/01/2021.
//
#include <vector>
#include <iostream>
using namespace std;
int Maximum_Sum(vector<vector<int>> &mat,int N,int K) {
    vector<vector<int>> psm(N, vector<int>(N, 0));

    psm[0][0] = mat[0][0];
    int maxSum = psm[0][0];
    for (int i = 1; i < N; ++i) {
        psm[i][0] = psm[i-1][0] + mat[i][0];
    }

    for (int j = 1; j < N; ++j) {
        psm[0][j] = psm[0][j-1] + mat[0][j];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            psm[i][j] = psm[i-1][j] + psm[i][j-1] - psm[i-1][j-1] + mat[i][j];
            int left = i-K >= 0 ? psm[i-K][j] : 0;
            int up = j-K >= 0 ? psm[i][j-K] : 0;
            int leftUp = i-K >= 0 && j-K >= 0 ? psm[i-K][j-K] : 0;

            int possibleNewMax = psm[i][j] - left - up + leftUp;
            if (possibleNewMax > maxSum) {
                maxSum = possibleNewMax;
            }
        }

    }

//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            cout << psm[i][j] << ' ';
//        }
//        cout << endl;
//    }
    return maxSum;
}