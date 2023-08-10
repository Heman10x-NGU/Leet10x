class Solution {
public:
    bool isValid(vector<int>& nums,int target,int p){
      int i=0;
      int countPairs=0;
      int n=nums.size();
      while(i<n-1){
        if(nums[i+1]-nums[i]<=target){
          countPairs++;
          //meaing a pair has been found
          // since if a pair has formed we 
          // cant use its elements again so
          i=i+2;
        }
        else{
          //no pair was formed so we can use the 2nd element
          // to form other pair or check
          i++;
        }
      }
      return countPairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int low=0,high=nums[n-1]-nums[0];
        while(low<=high){
          int mid=low + (high-low)/2;

          if(isValid(nums,mid,p)){
            ans=mid;
            high=mid-1;
            //meaning this works so we need lesser
          }
          else{
              low=mid+1;
          }
          
        }
        return ans;

        //TC= o(N*log(m)) m max diff, N number fo elements
    }
};