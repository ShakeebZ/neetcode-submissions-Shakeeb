class Solution {
public:
    bool isValid(string s) {
        std::stack<char> charStack;
        char pop;
        for (auto c : s) {
            if (c == ')' || c == '}' || c == ']') {
                if (charStack.empty()) {
                    return false;
                } else {
                    pop = charStack.top();
                    charStack.pop();
                    if ((c == ')') && (pop != '(')) {
                        return false;
                    } else if ((c == '}') && (pop != '{')) {
                        return false;
                    } else if ((c == ']') && (pop != '[')) {
                        return false;
                    }
                    continue;
                }
            }
            charStack.push(c);
        }
        return charStack.size() == 0;
    }
};
