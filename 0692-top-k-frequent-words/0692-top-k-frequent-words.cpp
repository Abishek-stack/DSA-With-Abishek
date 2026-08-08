class Solution {
public:
    static bool cmp(pair<string,int>&a , pair<string,int>&b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
       unordered_map<string,int> mp;
       for(int i = 0 ; i<words.size();i++){
        mp[words[i]]++;
       } 
       vector<pair<string,int>> temp;
       for(unordered_map<string,int>::iterator it = mp.begin();it!=mp.end();it++){
        temp.push_back(*it);
       }
       sort(temp.begin(),temp.end(),cmp);
       vector<string> ans;
       for(int i = 0 ; i<k;i++){
        ans.push_back(temp[i].first);
       }
       return ans;
    }
};