class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, equal = 0;

        for (int x : nums) {
            if (x < target) less++;
            else if (x == target) equal++;
        }

        vector<int> ans;

        for (int i = less; i < less + equal; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};