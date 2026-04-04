class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            j = i + 1;
            while (j < nums.size()) {
                if (nums[j] == nums[i]) {
                    return true;
                }
                j++;
            }
        }
        return false;
    }
};