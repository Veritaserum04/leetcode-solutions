class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i+1);
        }

        int ans = INT_MAX;

        for (auto& [num, indices] : mp) {
            for (int i = 0; i + 2 < indices.size(); i++) {
                ans = min(ans, 2 * (indices[i + 2] - indices[i]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};