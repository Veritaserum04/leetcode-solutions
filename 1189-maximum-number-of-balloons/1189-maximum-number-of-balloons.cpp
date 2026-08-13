class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> words;
        for(char c:text){
            words[c]++;
        }
        return min({
            words['b'],
            words['a'],
            words['l'] / 2,
            words['o'] / 2,
            words['n']
        }
        );
    }
};