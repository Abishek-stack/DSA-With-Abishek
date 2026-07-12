class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 , maxcount = 0;
        for(int i = 0 ; i <nums.size() ; i++){
            if(nums[i] == 1){
                count +=1;
                maxcount = max(count , maxcount);
            } else{
                count = 0;
            }
        }
        return maxcount;
    }
};