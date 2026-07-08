class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos, digit;

        // Store positions and values of non-zero digits
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = digit.size();

        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefValue(k + 1, 0);
        vector<long long> prefSum(k + 1, 0);

        for (int i = 1; i <= k; i++) {
            prefValue[i] = (prefValue[i - 1] * 10 + digit[i - 1]) % MOD;
            prefSum[i] = prefSum[i - 1] + digit[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            auto itL = lower_bound(pos.begin(), pos.end(), l);
            auto itR = upper_bound(pos.begin(), pos.end(), r);

            // No non-zero digit in this substring
            if (itL == itR) {
                ans.push_back(0);
                continue;
            }

            int L = (itL - pos.begin()) + 1; // 1-based
            int R = (itR - pos.begin());     // 1-based

            int len = R - L + 1;

            long long value = (prefValue[R] -
                               prefValue[L - 1] * pow10[len] % MOD +
                               MOD) % MOD;

            long long sum = prefSum[R] - prefSum[L - 1];

            ans.push_back((value * (sum % MOD)) % MOD);
        }

        return ans;
    }
};