class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << (col - 1));
        }
        int ans = 2 * n;
        int left = 0b0000011110;
        int middle = 0b0001111000;
        int right = 0b0111100000;

        for (auto &[row, reserved] : rows) {

            bool canLeft = (reserved & left) == 0;
            bool canMiddle = (reserved & middle) == 0;
            bool canRight = (reserved & right) == 0;

            if (canLeft && canRight) {
                ans += 0;
            }
            else if (canLeft || canMiddle || canRight) {
                ans -= 1;
            }
            else {
                ans -= 2;
            }
        }

        return ans;
    }
};