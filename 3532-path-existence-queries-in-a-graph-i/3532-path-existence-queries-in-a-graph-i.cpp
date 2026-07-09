class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
         vector<bool> ans;
        vector<int> component(n);
        component[0] = 0;
        for(int i = 1 ; i<n ; i++){
            if(nums[i] - nums[i-1] <=maxDiff){
                component[i] = component[i-1];
            } else{
                component[i] = component[i-1] + 1;
            }
        }
            for (int i = 0; i < queries.size(); i++) {
              vector<int> &q = queries[i];
               ans.push_back(component[q[0]] == component[q[1]]);
                     }
        
        return ans;
    }
};