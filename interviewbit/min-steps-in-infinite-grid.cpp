#include <iostream>
#include <vector>

class Solution {
    public:
        static int coverPoints(std::vector<int> & A, std::vector<int> & B);
};

int distance(int x1, int x2, int y1, int y2) {
    int xdiff = x1 > x2 ? x1 - x2 : x2 -x1;
    int ydiff = y1 > y2 ? y1 - y2 : y2 -y1;
    return xdiff > ydiff ? xdiff : ydiff;
}

int Solution::coverPoints(std::vector<int> & A, std::vector<int> & B) {
    int sum = 0;
    for (int i = 0; i < A.size()-1; i++) {
        sum += distance(A[i], A[i+1], B[i], B[i+1]);
    }
    return sum;
}

int main (int argc, char *argv[]) {
    std::vector<int> A = { 4, 8, -7, -5, -13, 9, -7, 8};
    std::vector<int> B = {4, -15, -10, -3, -13, 12, 8, -8};   
    std::cout << Solution::coverPoints(A, B) << "\n";
    return 0;
}

