class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> mp;
        for(int i:arr){
            if(mp.count(2*i)) return true;
            if(i % 2==0 && mp.count(i/2)) return true;
            mp.insert(i);
        }
        return false;
    }
};