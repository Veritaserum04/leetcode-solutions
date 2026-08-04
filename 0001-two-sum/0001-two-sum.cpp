class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> mp;

        for(int i = 0; i < nums.size(); i++) {
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    mp.push_back(i);
                    mp.push_back(j);
                    return mp;
                }
            }
        }
           
        return {};
    }
};