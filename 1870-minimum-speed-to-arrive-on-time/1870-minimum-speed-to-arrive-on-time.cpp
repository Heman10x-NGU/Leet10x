class Solution {
public:
    double findTime(vector<int>& dist,int mid){
      double total=0.0;
      int n=dist.size();
      for(int i=0;i<dist.size()-1;i++){
        double t = (double)(dist[i])/(double)(mid);
        total+=ceil(t);
      }
     total+=(double)(dist[n-1])/(double)(mid);
      return total;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=1e7;

        int min_speed=-1;

        while(low<=high){
          int mid_speed=low + (high-low)/2;

          if(findTime(dist,mid_speed)<=hour){
            min_speed=mid_speed;
            high=mid_speed-1;
          }
          else{
            low=mid_speed+1;
          }
        }
        return min_speed;
    }
};