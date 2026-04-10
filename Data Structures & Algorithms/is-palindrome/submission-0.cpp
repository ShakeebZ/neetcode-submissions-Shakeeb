class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        for (char c : s) {
            if (isalnum(c)) {
                newS += tolower(c);
            }
        }
        if (newS.size() < 2) return true;
        char* front = &newS[0];
        char* back = &newS[newS.size() - 1];
        for (int i = 0; i < newS.size()/2; i++) {
            if (*front != *back) {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
};
