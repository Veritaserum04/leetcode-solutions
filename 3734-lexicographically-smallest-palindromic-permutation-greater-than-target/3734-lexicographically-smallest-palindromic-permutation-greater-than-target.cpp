class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), cnt[26] = {};

        for (char c : s) cnt[c - 'a']++;

        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                if (mid != -1) return "";
                mid = i;
            }
            cnt[i] /= 2;
        }

        int h = n / 2;
        string left;
        int pos = 0;

        // Match target's left half
        while (pos < h && cnt[target[pos] - 'a']) {
            left += target[pos];
            cnt[target[pos] - 'a']--;
            pos++;
        }

        auto build = [&](string L) {
            string R = L;
            reverse(R.begin(), R.end());

            string ans = L;
            if (mid != -1)
                ans += char('a' + mid);
            ans += R;

            return ans;
        };

        // First try the exact matching left half
        if (pos == h) {
            string ans = build(left);

            if (ans > target)
                return ans;
        }

        // Try making the current position larger.
        // This also handles pos == 0.
        while (true) {
            int x = target[pos] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (!cnt[c]) continue;

                string L = left + char('a' + c);
                cnt[c]--;

                // Smallest possible remaining half
                for (int k = 0; k < 26; k++) {
                    while (cnt[k]) {
                        L += char('a' + k);
                        cnt[k]--;
                    }
                }

                return build(L);
            }

            // Cannot make this position larger.
            if (pos == 0) break;

            // Backtrack
            pos--;
            cnt[target[pos] - 'a']++;
            left.pop_back();
        }

        return "";
    }
};