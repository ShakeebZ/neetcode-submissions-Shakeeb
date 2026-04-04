class Solution {
public:
    bool checkIfAnagram(const string& str1, const string& str2) {
        if (str1.size() != str2.size()) return false;
        std::unordered_map<char, uint32_t> letters1;
        std::unordered_map<char, uint32_t> letters2;
        for (int i = 0; i < str1.size(); i++) {
            letters1[str1[i]]++;
            letters2[str2[i]]++;
        }
        return letters1 == letters2;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return {{}};
        if (strs.size() == 1) return {{strs.at(0)}};
        std::unordered_map<string, vector<string>> anagramsMap;
        anagramsMap[strs[0]] = {strs[0]};
        bool missed = true;
        for (int i = 1; i < strs.size(); i++) {
            missed = true;
            for (auto& [key, value] : anagramsMap) {
                if (checkIfAnagram(key, strs[i])) {
                    value.push_back(strs[i]);
                    missed = false;
                    continue;
                }
            }
            if (missed) {
                anagramsMap[strs[i]] = {strs[i]};
            }
        }
        vector<vector<string>> sol;
        for (auto& [key, value] : anagramsMap) {
            sol.push_back(value);
        }
        return sol;
    }
};
