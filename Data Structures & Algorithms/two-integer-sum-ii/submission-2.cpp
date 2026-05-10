class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> sol;
        int frontID = 0;
        int backID = numbers.size() - 1;
        int* front = &numbers[frontID];
        int* back = &numbers[backID];
        while (numbers[frontID] + numbers[backID] != target) {
            if (numbers[frontID] + numbers[backID] > target) {
                backID--;
                continue;
            } else {
                frontID++;
                continue;
            }
        }
        sol.push_back(frontID + 1);
        sol.push_back(backID + 1);
        return sol;
    }
};
