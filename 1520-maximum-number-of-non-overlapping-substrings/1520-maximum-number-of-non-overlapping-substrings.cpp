class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, s.size()), last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int ch = s[i] - 'a';
                if (first[ch] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[ch]);
            }

            if (valid)
                intervals.push_back({l, r});
        }
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 if (a.second == b.second)
                     return a.first < b.first;
                 return a.second < b.second;
             });

        vector<string> ans;
        int end = -1;

        for (auto &p : intervals) {
            if (p.first > end) {
                ans.push_back(s.substr(p.first, p.second - p.first + 1));
                end = p.second;
            }
        }

        return ans;
    }
};