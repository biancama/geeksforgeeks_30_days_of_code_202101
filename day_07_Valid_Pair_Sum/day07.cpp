//
// Created by Massimo Biancalani on 01/02/2021.
//
#include <algorithm>
long long ValidPair(int a[], int n)
{
    std::sort(&a[0], &a[n]);
    long long result = 0;
    int firstNegative = 0;
    while(n - firstNegative > 0) {
        if (a[n-1] <= 0) {
            break;
        }
        firstNegative = std::lower_bound(&a[firstNegative], &a[n], -a[n-1] + 1) - &a[0];
        result += n - firstNegative - 1;
        n--;
    }
    return result;
}