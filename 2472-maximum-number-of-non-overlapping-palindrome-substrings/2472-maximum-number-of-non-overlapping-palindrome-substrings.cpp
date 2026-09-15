class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1]; 
            if (i + k <= n && isPalindrome(s, i, i + k - 1)) {
                dp[i] = max(dp[i], 1 + dp[k + i]);
            }
            if (i + k + 1 <= n && isPalindrome(s, i, i + k)) {
                dp[i] = max(dp[i], 1 + dp[i + k + 1]);
            }
        }

        return dp[0];
    }
};