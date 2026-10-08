class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int ans = 0;
        for (char c : s) {
            if (c == '(') {
                if (ans > 0) res += c;
                    ans++;
            } else {
                    ans--;
                if (ans > 0) res += c;
            }
        }
        return res;
    }
};