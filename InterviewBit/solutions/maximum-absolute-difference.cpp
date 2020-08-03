#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

int maxArr(std::vector<int> & A) {
    int max = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            if (i == j || i > j) continue;
            int abs_diff = abs(A[i] - A[j]) + abs(i - j);
            if (abs_diff > max) 
                max = abs_diff;
        }
    }
    return max;
}

int main (int argc, char *argv[]) {
    std::vector<int> v1 = {55, -8, 43, 52, 8, 59, -91, -79, -18, -94};
    std::cout << maxArr(v1) << "\n";
    return 0;
}

