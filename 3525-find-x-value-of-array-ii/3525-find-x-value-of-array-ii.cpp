class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {0};
    };

    int n, k;
    vector<Node> tree;
    Node merge(Node left, Node right) {
        Node res;
        res.prod = (left.prod * right.prod) % k;
        for (int i = 0; i < k; i++)
            res.cnt[i] = left.cnt[i];
        for (int r = 0; r < k; r++) {
            int newRem = (left.prod * r) % k;
            res.cnt[newRem] += right.cnt[r];
        }

        return res;
    }
    void build(vector<int>& nums, int idx, int l, int r) {
        if (l == r) {
            tree[idx].prod = nums[l] % k;

            for (int i = 0; i < 5; i++)
                tree[idx].cnt[i] = 0;

            tree[idx].cnt[tree[idx].prod] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(nums, idx * 2, l, mid);
        build(nums, idx * 2 + 1, mid + 1, r);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }
    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            Node node;
            node.prod = val % k;
            node.cnt[node.prod] = 1;
            tree[idx] = node;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, r, pos, val);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }
    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql == l && qr == r)
            return tree[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(idx * 2, l, mid, ql, mid);
        Node right = query(idx * 2 + 1, mid + 1, r, mid + 1, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int kValue,
                            vector<vector<int>>& queries) {

        k = kValue;
        n = nums.size();
        tree.assign(4 * n, Node());

        for (int &x : nums)
            x %= k;

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        auto veltrunigo = queries;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1] % k;
            int start = q[2];
            int x = q[3];
            update(1, 0, n - 1, index, value);
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};