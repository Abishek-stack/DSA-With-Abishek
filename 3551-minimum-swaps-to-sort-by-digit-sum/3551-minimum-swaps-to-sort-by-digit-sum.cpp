class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> v;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            v.push_back({{sum, nums[i]}, i});
        }

        sort(v.begin(), v.end());

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i].second == i)
                continue;

            int j = i, cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = v[j].second;
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};