class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> nums;
        int next_num = 0;
        int temp = 0;
        while (true) {
            if (n == 1) {
                return true;
            } else if (nums.count(n)) {
                return false;
            }
            nums.insert(n);
            while (n != 0) {
                temp = n % 10;
                n = n / 10;
                next_num += temp * temp;
            }
            n = next_num;
            next_num = 0;
        }
    }
};
