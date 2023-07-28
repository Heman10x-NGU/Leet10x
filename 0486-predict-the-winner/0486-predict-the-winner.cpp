class Solution {
public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){ // function is jjust for player1
      if(i>j){
        return 0;
      }

      if(i==j){
        return nums[i];
      }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
      int take_i = nums[i] - solve(i+1,j,nums,dp);
      int take_j = nums[j] - solve(i,j-1,nums,dp);

      //here we tried to do our best, and we expected the worst so took min

      return dp[i][j]=max(take_i,take_j);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        int diff=solve(0,n-1,nums,dp);

        
        
        return diff>=0;
    }
};