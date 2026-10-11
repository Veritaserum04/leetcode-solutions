class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size=nums.size();
        int ans=0;
        if(size < 2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<size;i++){
            ans=max(ans,nums[i]-nums[i-1]);
        }
        return ans;
    }
};