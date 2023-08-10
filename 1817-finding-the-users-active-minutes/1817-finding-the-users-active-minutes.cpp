class Solution {
public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
       int n=logs.size();
       
       unordered_map<int,unordered_set<int>> mp;
       //{id,{times,we need unique actions done by this id}_thats why set}
       
       for(int i=0;i<n;i++){
         mp[logs[i][0]].insert(logs[i][1]);
       } 
       //insert unique times done by per Id
       vector<int> ans(k,0);

       for(auto it:mp){
         int sizeOfUAM=it.second.size();
         ans[sizeOfUAM-1]++;
         //sizeof UAM as to make th array 1 indexed
       }
       return ans;

       //tc=O(n) no log n as we dont use ordered set or map
       //sc= o(n)
    }
};