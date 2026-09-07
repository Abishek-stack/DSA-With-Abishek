class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int s = nums.size();
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0 ; i < s ; i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};