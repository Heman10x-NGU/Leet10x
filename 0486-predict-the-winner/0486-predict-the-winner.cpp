class Solution {
public:
    int solve(int i,int j,vector<int>& nums){ // function is jjust for player1
      if(i>j){
        return 0;
      }

      if(i==j){
        return nums[i];
      }
      int take_i = nums[i] + min(solve(i+2,j,nums) , solve(i+1,j-1,nums));
      int take_j = nums[j] + min(solve(i,j-2,nums) , solve(i+1,j-1,nums));

      //here we tried to do our best, and we expected the worst so took min

      return max(take_i,take_j);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        int player1_Score=solve(0,n-1,nums);
        int player2_Score=total-player1_Score;
        
        return player1_Score>=player2_Score;
    }
};