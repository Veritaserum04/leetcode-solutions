class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        vector<vector<int>> right(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == t[j]) {
                    left[i][j] = 1;
                    if (i > 0 && j > 0)
                        left[i][j] += left[i - 1][j - 1];
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    right[i][j] = 1;
                    if (i + 1 < m && j + 1 < n)
                        right[i][j] += right[i + 1][j + 1];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] != t[j]) {
                    int leftMatch = (i > 0 && j > 0) ? left[i - 1][j - 1] : 0;
                    int rightMatch = (i + 1 < m && j + 1 < n) ? right[i + 1][j + 1] : 0;
                    ans += (leftMatch + 1) * (rightMatch + 1);
                }
            }
        }
        return ans;
    }
};