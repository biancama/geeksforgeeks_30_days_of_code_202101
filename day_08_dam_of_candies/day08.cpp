//
// Created by Massimo Biancalani on 02/02/2021.
//

#include <algorithm>

int maxCandy(int height[], int n) {
    int i = 0, j = n-1;
    unsigned int area = 0;
    while(i + 1 <= j) {
        unsigned int newArea = (j -1 -i) * std::min(height[i], height[j]);
        if (newArea > area) {
            area = newArea;
        }
        if (height[j] > height[i]) {
            i++;
        } else {
            j--;
        }
    }
    return area;
}