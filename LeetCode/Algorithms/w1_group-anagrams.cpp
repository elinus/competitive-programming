class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> agm_grp;
        map<string, int> lookup;
        int index = 0;
        for(auto i = 0; i < strs.size(); ++i) {
            vector<int> alpha(26, 0);
            for(auto j = 0; j < strs[i].size(); j++) {
                alpha[strs[i][j] - 'a']++;
            }
            
            string key = "";
            for(int k = 0; k < 26; k++) {
                if(!alpha[k]) continue;
                while(alpha[k]--) {
                    key += (char)('a' + k);
                }
            }
            if (lookup.find(key) == lookup.end()) {
                agm_grp.push_back({});
                agm_grp[index].push_back(strs[i]);
                lookup[key] = index++;
            } else {
                int x = lookup[key];
                agm_grp[x].push_back(strs[i]);
            }
        }
        return agm_grp;
    }
};
