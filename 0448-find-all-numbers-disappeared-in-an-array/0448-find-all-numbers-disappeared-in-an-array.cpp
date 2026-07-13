class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int j = 0;
        int a = nums.size();
        for(int i = 1 ; i <= a ;i++){
          while(j < a && nums[j] < i){
            j++;
          }
          if(j == a || nums[j] != i){
            ans.push_back(i);
          }
        }
        return ans;
    }
};