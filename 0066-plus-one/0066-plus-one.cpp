class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int j=n-1;j>=0;j--){
            if(digits[j] < 9){
                digits[j]++;
                return digits;
            }
            digits[j]=0;  
        }
        digits.insert(digits.begin(),1); 
        return digits;
    }
};