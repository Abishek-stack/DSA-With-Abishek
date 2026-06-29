class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum = 0, count = INT_MAX;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while (sum >= target) {

                count = min(count, right - left + 1);

                sum -= nums[left];
                left++;
            }
        }

        if (count == INT_MAX)
            return 0;

        return count;
    }
};