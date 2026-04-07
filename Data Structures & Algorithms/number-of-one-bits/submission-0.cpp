class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 32;
        int numOnes = 0;
        while (count != 0) {
            if (n & 1) numOnes++;
            n = n >> 1;
            count--;
        }
        return numOnes;
    }
};
