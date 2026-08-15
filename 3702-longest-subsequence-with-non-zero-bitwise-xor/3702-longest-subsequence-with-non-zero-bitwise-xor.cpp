class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool allZero = true;

        for (int x : nums) {
            xr ^= x;
            if (x != 0) allZero = false;
        }

        if (xr != 0) return nums.size();
        if (allZero) return 0;
        return nums.size() - 1;
    }
};