class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> A, B;

        int n = img1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) A.push_back({i, j});
                if (img2[i][j]) B.push_back({i, j});
            }
        }

        map<pair<int,int>, int> count;
        int ans = 0;

        for (auto &a : A) {
            for (auto &b : B) {
                pair<int,int> shift = {b.first - a.first,
                                       b.second - a.second};

                ans = max(ans, ++count[shift]);
            }
        }

        return ans;
    }
};