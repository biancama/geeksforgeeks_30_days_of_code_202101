//
// Created by Massimo Biancalani on 29/01/2021.
//
int find_min(int a[], int n, int k) {
    int possiblePairs = 0;
    int optimalSocksPairs = 0;
    for (int i = 0; i < n; ++i) {
        possiblePairs += a[i] / 2;
        if (a[i] % 2 == 0) {
            optimalSocksPairs += (a[i] - 2) / 2;
        } else {
            optimalSocksPairs += (a[i] - 1) / 2;
        }
    }

    if (possiblePairs < k) {
        return -1;
    }
    if (k <= optimalSocksPairs) {
        return 2 * (k - 1) + n + 1;
    } else {
        return 2 * optimalSocksPairs + (k - optimalSocksPairs) + n;
    }
}