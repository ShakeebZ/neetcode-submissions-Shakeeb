class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());
        int prod = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pre[i] = prod;
            prod *= nums[i];
        }
        prod = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            suf[i] = prod;
            prod *= nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            output[i] = pre[i] * suf[i];
        }
        output[0] = suf[0];
        output[nums.size() - 1] = pre[nums.size() - 1];
        return output;
};
};