class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numsMap;
        for (int i = 0; i < nums.size(); i++) {
            numsMap[nums[i]] = i;
        }
        int val1;
        int id2;
        for (int i = 0; i < nums.size(); i++) {
            val1 = nums[i];
            if (numsMap.contains(target - val1)) {
                id2 = numsMap[target - val1];
                if (i != id2) {
                    return vector<int>{i, id2};
                }
            }
        }
        return vector<int>{0, 1};
    }
};
