class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for (auto n : nums) {
            val ^= n;
        }
        return val;
    }
};
