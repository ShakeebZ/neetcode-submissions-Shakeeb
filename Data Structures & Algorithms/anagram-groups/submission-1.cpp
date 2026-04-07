class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> sortedAnagrams;
        vector<string> strings = strs;
        for (int i = 0; i < strs.size(); i++) {
            std::sort(strings[i].begin(), strings[i].end());
            sortedAnagrams[strings[i]].push_back(strs[i]);
        }
        vector<vector<string>> sol;
        for (auto& keyValue : sortedAnagrams) {
            sol.push_back(keyValue.second);
        }
        return sol;
    }
};
