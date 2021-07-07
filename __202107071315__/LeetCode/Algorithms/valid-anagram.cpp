class Solution {
    
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> ms, mt;
        for (int i = 0; i < s.size(); ++i) {
            if (ms.find(s[i]) != ms.end()) {
                ms[s[i]] += 1;
            } else {
                ms[s[i]] = 1;
            }
            if (mt.find(t[i]) != mt.end()) {
                mt[t[i]] += 1;
            } else {
                mt[t[i]] = 1;
            }
        }
        if (ms == mt) return true;
        return false;
    }
};
