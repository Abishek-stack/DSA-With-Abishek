class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j =0 ;
        for( int i = 1 ; i <= n ; i++){
            ans.push_back("Push");
            if(i == target[j]){ 
                j++;

            }else{
                 ans.push_back("Pop");
            }

        if (j == target.size())
                break;
        
          
        }
       return ans;
    }
     
};