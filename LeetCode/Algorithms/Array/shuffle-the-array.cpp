#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(const vector<T> & vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
    cout << "\n";
}

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int ne = n;
        
        for (int i = 0; n > 0; i = i + 2) {
            int tmp = nums[i + n];
            for (int j = ne - 1; j > i; j--) {
                nums[j+1] = nums[j];
            }
            nums[i + 1] = tmp;
            n--;
            ne++;
        }
        return nums;
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution obj;
    vector<int> v1 = {2,5,1,3,4,7};
    print(obj.shuffle(v1, 3));

    vector<int> v2 = {1,2,3,4,4,3,2,1};
    print(obj.shuffle(v2, 4));

    vector<int> v3 = {1,1,2,2};
    print(obj.shuffle(v3, 2));
    return 0;
}
