class Solution {
public:
    bool isPalindrome(string s) {
        string alph="";
        for(char c:s){
            if(isalnum(c)){
                alph+=tolower(c);
            }
        }
        string rev=alph;
        reverse(rev.begin(),rev.end());
        if(rev==alph) return true;
        else return false;
    }
};