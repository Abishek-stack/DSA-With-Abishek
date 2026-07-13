class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a = 0 , count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(count ==0){
                a = nums[i];
            }
            if(nums[i]==a){
                count++;
            }
            else{
                count--;
            }
        }
        return a;
    }
};