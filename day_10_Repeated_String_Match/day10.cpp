//
// Created by Massimo Biancalani on 04/02/2021.
//
#include <string>
using namespace std;
int repeatedStringMatch(string A, string B)
{
    int count = B.size() / A.size();
    string aux(A);
    int result = 1;
    for(int i = 0; i < count + 2; ++i) {
        if (aux.find(B) != string::npos) {
            return result;
        } else {
            aux.append(A);
            result++;
        }
    }
    return -1;
}