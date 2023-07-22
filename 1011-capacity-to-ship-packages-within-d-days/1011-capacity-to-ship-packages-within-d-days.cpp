class Solution {
public:
    int findDays(vector<int>& w,int d,int cap){
      int totalload=0;
      int days=1;
      int n=w.size();
      for(int i=0;i<n;i++){
        if(w[i]+totalload>cap){
          days++;
          totalload=w[i];
        }
        else{
          totalload+=w[i];
        }
      }
      return days;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 0;
        for (int w: weights){
            left = max(left, w);
            right+=w;
        }
            
            
            while(left <= right){
                    int mid= left + (right-left)/2;
                    int days=findDays(weights,D,mid);
                    
                    if(days>D){
                            left=mid+1;
                    }
                    else{
                            right=mid-1;
                    }
            }
        //         while (left < right) 
        //         {
        //          int mid = (left + right) / 2, need = 1, cur = 0;
        //          for (int i = 0; i < weights.size() && need <= D; cur += weights[i++])
        //           if (cur + weights[i] > mid)
        //             cur = 0, need++;
        //          if (need > D) left = mid + 1;
        //          else right = mid;
        // }
        return left;
    }
};