class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> result;
        set<string> curr = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                result.insert(curr.begin(), curr.end());
                curr = {""};
                i++;
            }

            else {
                set<string> next;

                if (s[i] == '{') {
                    i++;                      
                    next = parse(s, i);        
                    i++;                       
                }

                else {
                    string t;
                    t += s[i++];
                    next.insert(t);
                }
                set<string> temp;
                for (auto &a : curr)
                    for (auto &b : next)
                        temp.insert(a + b);

                curr = temp;
            }
        }
        result.insert(curr.begin(), curr.end());
        return result;
    }
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};