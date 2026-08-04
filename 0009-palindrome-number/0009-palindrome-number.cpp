class Solution {
public:
    bool isPalindrome(int x) {
        long rev=0;
        int dup=x;
        if(x<0) return false;
        if(x>=0 && x<=9) return true;
        while(x>0){
            int last=x%10;
            x=x/10;
            rev=(rev*10)+last;
        }
        
        if(rev==dup) return true;
        else return false;
        
    }
};