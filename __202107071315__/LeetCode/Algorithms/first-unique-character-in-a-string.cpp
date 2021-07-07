class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count_map;
        unordered_map<char, int> index_map;
        for (auto i = 0; i < s.size(); ++i) {
            if (index_map.find(s[i]) != index_map.end()) {
                count_map[s[i]] += 1;
            } else {
                index_map[s[i]] = i;
                count_map[s[i]] = 1;
            }
        }
        int result = -1;
        int min_index = INT_MAX;
        for (auto i = count_map.begin(); i != count_map.end(); ++i) {
            if (i->second == 1) {
                auto it = index_map.find(i->first);
                if (it != index_map.end()) {
                    if (min_index > it->second) {
                        min_index = it->second;
                        result = min_index;
                    }
                }
            }
        }
        return result;
    }
};
