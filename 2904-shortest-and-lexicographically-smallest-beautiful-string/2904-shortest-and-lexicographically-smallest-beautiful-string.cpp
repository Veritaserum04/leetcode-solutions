class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int l = 0, cnt = 0;

        for (int r = 0; r < s.size(); r++) {
            cnt += s[r] == '1';

            while (cnt > k)
                cnt -= s[l++] == '1';

            while (l <= r && s[l] == '0')
                l++;

            if (cnt == k) {
                string t = s.substr(l, r - l + 1);
                if (ans.empty() || t.size() < ans.size() ||
                    (t.size() == ans.size() && t < ans))
                    ans = t;
            }
        }
        return ans;
    }
};