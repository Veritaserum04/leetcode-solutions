class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visited;
        for(int i:nums){
            if(visited.count(i)) return true;
            visited.insert(i);
        }
        return false;
    }
};