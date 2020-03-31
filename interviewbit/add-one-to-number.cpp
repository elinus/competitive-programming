#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> plusOne(std::vector<int> &A) {
    if (A.empty()) return {};
    std::reverse(A.begin(), A.end());

    while(A.back() == 0 && A.size() > 1) {
        A.pop_back();
    }


    int carry = 0;
    if ((A[0] + 1) > 9) {
        carry = 1;
        A[0] = 0;
    } else {
        A[0] += 1;
        carry = 0;
    }
    for (int i = 1; i < A.size(); i++) {
        if ((A[i] + carry) > 9) {
            carry = 1;
            A[i] = 0;
        } else {
            A[i] += carry;
            carry = 0;
        }
    }
    if (carry) {
        A.push_back(carry);
    }
    std::reverse(A.begin(), A.end());
    std::vector<int> res(A);
    return res;
}

int main (int argc, char *argv[]) {
    std::vector<int> v1 = {0};
    auto v2 = plusOne(v1);
    for (auto it = v2.begin(); it != v2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}

