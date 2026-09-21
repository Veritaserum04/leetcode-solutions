class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            vector<long long> newDp(k, 0);
            int mod = num % k;
            newDp[mod]++;
            for (int r = 0; r < k; r++) {
                int newMod = (r * mod) % k;
                newDp[newMod] += dp[r];
            }
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }
            dp = newDp;
        }
        return ans;
    }
};