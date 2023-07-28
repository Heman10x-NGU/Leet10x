class Solution {
public:
    int dp[2][101][101];

    int solveForAlice(vector<int>& piles,int person,int i,int M){
      int n=piles.size();
      if(i>=piles.size()){
        return 0;
      }

      if(dp[person][i][M]!=-1){
        return dp[person][i][M];
      }

      int result=person?-1:INT_MAX;

      int stones=0;
      for(int x=1;x<=min(2*M,n-i);x++){

        stones += piles[i+x-1];

        if(person==1){ //Alice playing
          result=max(result,stones + solveForAlice(piles,0,i+x,max(M,x)));
        }
        else{
          result = min(result,solveForAlice(piles,1,i+x,max(M,x)));
        }
      }

      return dp[person][i][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));

        return solveForAlice(piles,1,0,1);
    }
};