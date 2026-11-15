
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long even = 1, odd = 0;
        long long prefix = 0, ans = 0;

        for (int num : arr) {
            prefix += num;

            if (prefix % 2 == 0) {
                ans += odd;
                even++;
            } 
            else {
                ans += even;
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};
