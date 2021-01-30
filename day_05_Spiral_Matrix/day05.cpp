//
// Created by Massimo Biancalani on 30/01/2021.
//

#include <vector>
#include <iostream>
using namespace std;
int findK(vector<vector<int>> &a, int n, int m, int k) {
    unsigned int step = 0, i = 0, j = 0;
    int minRow = 0, maxRow = n - 1;
    int minColumn = 0, maxColumn = m - 1;
    char movement = 'R';
    int result =0;

    while (step < k) {
        result = a[i][j];
        cout << result << ' ';
        step++;
        switch (movement) {
            case 'R':
                if (j == maxColumn) {
                    movement = 'D';
                    minRow++;
                    i++;
                } else {
                    j++;
                }
                break;
            case 'D':
                if (i == maxRow) {
                    movement = 'L';
                    maxColumn--;
                    j--;
                } else {
                    i++;
                }
                break;
            case 'L':
                if (j == minColumn) {
                    movement = 'U';
                    maxRow--;
                    i--;
                } else {
                    j--;
                }
                break;
            case 'U':
                if (i == minRow) {
                    movement = 'R';
                    minColumn++;
                    j++;
                } else {
                    i--;
                }
                break;
        }
    }

    return result;
}