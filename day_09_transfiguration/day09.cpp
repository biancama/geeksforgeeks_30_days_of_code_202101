//
// Created by Massimo Biancalani on 02/02/2021.
//
#include <string>
#include <map>
using namespace std;
int transfigure (string A, string B)
{
    if (A.size() != B.size()) {
        return -1;
    }
    map<char,int> mapForA, mapForB;
    for(int i = 0; i < A.size(); ++i) {
        mapForA[A[i]]++;
        mapForB[B[i]]++;
    }
    if (!equal(mapForA.begin(), mapForA.end(), mapForB.begin())) {
        return -1;
    }
    int result = 0;
    for(int i = A.size() -1, j = B.size() -1 ; i >= 0; --i) {
        if (A[i] == B[j]) {
            --j;
        } else {
            result++;
        }
    }
    return result;
}
