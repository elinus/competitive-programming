class Solution {
public:
    string removeDuplicates(string S) {
        string result;
        for (int i = 0; i < S.size(); i++) {
            if (!result.empty() && result[result.size() - 1] == S[i]) {
                result.pop_back();
            } else {
                result += S[i];
            }
        }
        return result;
    }
};
