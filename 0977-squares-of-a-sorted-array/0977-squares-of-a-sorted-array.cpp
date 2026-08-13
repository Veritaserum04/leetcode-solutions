class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int left=0;
        int right=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            int numleft=nums[left]*nums[left];
            int numright=nums[right]*nums[right];
            if(numleft>numright){
                ans[i]=numleft;
                left++;
            }else{
                ans[i]=numright;
                right--;
            }
        }
        return ans;
    }
};