class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int c[26] = {};
        for(char x:s) c[x-'a']++;

        for(int i=0;i<t.size();i++) {
            int x=t[i]-'a';

            if(c[x]) c[x]--;
            else {
                for(int j=x+1;j<26;j++) if(c[j]) {
                    string a=t.substr(0,i)+char('a'+j);
                    c[j]--;
                    for(int k=0;k<26;k++) a+=string(c[k],'a'+k);
                    return a;
                }
                i--;
                while(i>=0) {
                    c[t[i]-'a']++;
                    for(int j=t[i]-'a'+1;j<26;j++) if(c[j]) {
                        string a=t.substr(0,i)+char('a'+j);
                        c[j]--;
                        for(int k=0;k<26;k++) a+=string(c[k],'a'+k);
                        return a;
                    }
                    i--;
                }
                return "";
            }
        }

        // t itself was possible, so find next permutation
        for(int i=t.size()-1;i>=0;i--) {
            c[t[i]-'a']++;
            for(int j=t[i]-'a'+1;j<26;j++) if(c[j]) {
                string a=t.substr(0,i)+char('a'+j);
                c[j]--;
                for(int k=0;k<26;k++) a+=string(c[k],'a'+k);
                return a;
            }
        }
        return "";
    }
};