class Solution {
public:
    int countCommas(int n) {
        int ans = 0;

        if (n >= 1000)
            ans += n - 999;

        if (n >= 1000000)
            ans += 2 * (n - 999999);

        if (n >= 1000000000)
            ans += 3 * (n - 999999999);

        return ans;
    }
};