class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int left=1;
            int n=nums.size();
            int right=INT_MIN;
            int ans=INT_MAX;
            for(int i=0;i<n;i++){
                  right=max(right,nums[i]);  
            }
            while(left<=right){
                    int mid=left + (right-left)/2;
                    int sum=0;
                    for(int i=0;i<n;i++){
                            sum+= nums[i]/mid + (nums[i]%mid!=0);
                    }
                    if(sum>threshold){
                             left=mid+1;
                          
                          
                    }
                    else{
                          //  ans=min(mid,ans);
                             right=mid-1;
                           
                            
                    }
            }
            return left;
    }
};