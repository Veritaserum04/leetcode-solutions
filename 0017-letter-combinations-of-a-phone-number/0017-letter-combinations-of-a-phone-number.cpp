class Solution {
public:
    vector<string> ans;

    vector<string> map = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int idx, string curr) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = map[digits[idx] - '0'];

        for (char ch : letters) {
            backtrack(digits, idx + 1, curr + ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        backtrack(digits, 0, "");
        return ans;
    }
};