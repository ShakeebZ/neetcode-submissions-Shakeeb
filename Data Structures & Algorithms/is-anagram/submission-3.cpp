class Solution {
public:
    // Original Working Solution
    bool OriginalisAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        std::unordered_map<char, int> sMap;
        std::unordered_map<char, int> tMap;
        for (int i = 0; i < s.size(); i++) {
            auto [sIter, sEmplaced] = sMap.try_emplace(s[i], 1);
            auto [tIter, tEmplaced] = tMap.try_emplace(t[i], 1);
            if (!sEmplaced) sIter->second++;
            if (!tEmplaced) tIter->second++;
        }
        if (sMap == tMap) return true;
        return false;
    }

    // Removed Redundancies
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        std::unordered_map<char, uint32_t> sMap;
        std::unordered_map<char, uint32_t> tMap;
        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }
        return sMap == tMap;
    }
};
