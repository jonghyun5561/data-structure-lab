#include <iostream>
#include <vector>
using namespace std;

int findMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal)
            maxVal = num;
    }
    return maxVal;
}

int main() {
    vector<vector<int>> Cases = {
        {3, 7, 2, 9, 10, 5},
        {-10, -5, -3},
        {100, 200, 300, 50, 400},
        {0, 0, -2, 0},
        {10000}
    };

    for (size_t i = 0; i < Cases.size(); ++i) {
        cout << "" << i + 1 << ": ";
        for (int num : Cases[i])
            cout << num << " ";
        cout << "=> ÃÖ´ñ°ª: " << findMax(Cases[i]) << endl;
    }

    return 0;
}

