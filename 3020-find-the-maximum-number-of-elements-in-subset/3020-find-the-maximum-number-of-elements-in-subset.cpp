class Solution {
public:
    int maximumLength(vector<int>& nums) {
      unordered_map<long long , int> mp;
      int ans = 1;
      for(int x : nums){
        mp[x]++;
      }  
      if(mp.count(1)){
        if(mp[1]%2==0){
            ans = max(ans , mp[1]-1);
        } else {
          ans =  max(ans , mp[1]);
        }
      }
      for(auto it:mp){
         long long x = it.first;
      

      if(x == 1)
        continue;

      long long cur = x;
      int len = 1;

      while(mp[cur] >= 2){
            if(cur > 1000000000LL / cur){
                break;
            } 
            long long next = cur*cur;
            if( ! mp.count(next))
                 break;
                len +=2;
                cur = next; }
      
               ans = max(ans , len);
               }
      return ans;
      
    }
};