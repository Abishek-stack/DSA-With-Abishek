class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        vector<int> ans = nums;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};