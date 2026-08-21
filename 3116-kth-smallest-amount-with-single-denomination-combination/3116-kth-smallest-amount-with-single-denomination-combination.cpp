class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countNumbers(vector<int>& coins, long long x) {
        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long curLcm = 1;
            bool valid = true;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    curLcm = lcm(curLcm, (long long)coins[i]);
                    if (curLcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            if (bits % 2 == 1)
                count += x / curLcm;
            else
                count -= x / curLcm;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1e18;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countNumbers(coins, mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};