class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;

        for(string op : operations) {
            if(op == "C") {
                stk.pop();
            }
            else if(op == "D") {
                stk.push(stk.top() * 2);
            }
            else if(op == "+") {
                int x = stk.top();
                stk.pop();

                int y = stk.top();
                stk.push(x);

                stk.push(x + y);
            }
            else {
                stk.push(stoi(op));
            }
        }

        int sum = 0;
        while(!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }

        return sum;
    }
};