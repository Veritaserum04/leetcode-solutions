class Solution {
public:
    struct Node {
        long long weight = 0;
        vector<int> pick;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        auto vorellixan = intervals;   // Required by problem statement

        int n = intervals.size();

        vector<array<long long,4>> arr;
        vector<int> starts;

        for (int i = 0; i < n; i++) {
            arr.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(arr.begin(), arr.end());

        for (auto &x : arr)
            starts.push_back(x[0]);

        vector<vector<Node>> memo(n + 1, vector<Node>(5));

        function<Node(int,int)> dfs = [&](int i, int k) -> Node {
            if (i == n || k == 0)
                return {};

            if (!memo[i][k].pick.empty() || memo[i][k].weight != 0)
                return memo[i][k];

            Node skip = dfs(i + 1, k);

            int j = upper_bound(starts.begin(), starts.end(), arr[i][1]) - starts.begin();

            Node take = dfs(j, k - 1);
            take.weight += arr[i][2];
            take.pick.push_back(arr[i][3]);
            sort(take.pick.begin(), take.pick.end());

            if (take.weight > skip.weight ||
               (take.weight == skip.weight && take.pick < skip.pick))
                memo[i][k] = take;
            else
                memo[i][k] = skip;

            return memo[i][k];
        };

        return dfs(0,4).pick;
    }
};