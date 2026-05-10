class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (string s : strs) {
            string length = to_string(s.length());
            for (auto c : length) {
                encoded.push_back(c);
            }
            encoded.push_back('#');
            for (auto c : s) {
                encoded.push_back(c);
            }
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        int size = 0;
        string curr = "";
        while (i < s.length()) {
            curr = "";
            size = 0;
            while (s[i] != '#') {
                size *= 10;
                size += s[i] - '0';
                i++;
            }
            // Get rid of the # symbol
            i++;
            while (size) {
                curr.push_back(s[i]);
                i++;
                size--;
            }
            decoded.push_back(curr);
        }
        return decoded;
    }
};
