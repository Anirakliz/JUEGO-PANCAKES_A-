#include <iostream>
#include <vector>
using namespace std;

void flip(vector<int>& pancakes, int k) {
    int i = 0;
    while (i < k) {
        swap(pancakes[i], pancakes[k]);
        i++;
        k--;
    }
}

int findMaxIndex(vector<int>& pancakes, int k) {
    int maxIndex = 0;
    for (int i = 0; i <= k; i++) {
        if (pancakes[i] > pancakes[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void pancakeSort(vector<int>& pancakes) {
    int n = pancakes.size();
    for (int i = n-1; i > 0; i--) {
        int maxIndex = findMaxIndex(pancakes, i);
        if (maxIndex != i) {
            flip(pancakes, maxIndex);
            flip(pancakes, i);
        }
    }
}

int main() {
    vector<int> pancakes = {10,8,7,9,4,1,3,5,2};
    pancakeSort(pancakes);
    for (int i = 0; i < pancakes.size(); i++) {
        cout << pancakes[i] << " ";
    }
    cout << endl;
    return 0;
}
