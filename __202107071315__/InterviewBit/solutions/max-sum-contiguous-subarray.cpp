#include <iostream>
#include <vector>
#include <climits>

int maxSubArray(const std::vector<int> & A) {
    int max_so_far = INT_MIN, max_end_here = 0;
    for (int i = 0; i < A.size(); i++) {
        max_end_here += A[i];
        if (max_end_here < 0)
            max_end_here = 0;
        else if (max_so_far < max_end_here) 
            max_so_far = max_end_here;
    }
    return max_so_far;
}

int main (int argc, char *argv[]) {
    
    return 0;
}

