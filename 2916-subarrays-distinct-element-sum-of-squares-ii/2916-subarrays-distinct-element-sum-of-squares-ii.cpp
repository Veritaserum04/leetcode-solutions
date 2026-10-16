class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> sum(4 * n), sq(4 * n), lazy(4 * n);
        vector<int> last(100001, -1);
        long long ans = 0;

        auto update = [&](auto&& self, int node, int l, int r,
                          int ql, int qr) -> void {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                sq[node] = (sq[node] + 2 * sum[node] + (r - l + 1)) % MOD;
                sum[node] = (sum[node] + (r - l + 1)) % MOD;
                lazy[node]++;
                return;
            }

            int mid = (l + r) / 2;

            if (lazy[node]) {
                for (int child : {node * 2, node * 2 + 1}) {
                    int len = child == node * 2 ? mid - l + 1 : r - mid;
                    sq[child] = (sq[child] + 2 * sum[child] * lazy[node]
                                 + len * lazy[node] * lazy[node]) % MOD;
                    sum[child] = (sum[child] + len * lazy[node]) % MOD;
                    lazy[child] += lazy[node];
                }
                lazy[node] = 0;
            }

            self(self, node * 2, l, mid, ql, qr);
            self(self, node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        for (int i = 0; i < n; i++) {
            update(update, 1, 0, n - 1, last[nums[i]] + 1, i);
            last[nums[i]] = i;
            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};