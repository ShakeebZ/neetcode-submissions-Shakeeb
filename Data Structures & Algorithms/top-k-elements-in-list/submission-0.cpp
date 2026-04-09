class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> freq;
        for (auto n : nums) {
            freq[n]++;
        }
        std::vector<std::pair<int, int>> frequencyVector;
        for (auto f : freq) {
            frequencyVector.push_back(std::pair<int, int>(f.first, f.second));
        }
        std::sort(frequencyVector.begin(), frequencyVector.end(), [] (std::pair<int, int> a, std::pair<int, int> b) {
            return a.second < b.second;
        });
        std::vector<int> sol;
        for (int i = 0; i < k; i++) {
            sol.push_back(frequencyVector.back().first);
            frequencyVector.pop_back();
        }
        return sol;
    }
};
