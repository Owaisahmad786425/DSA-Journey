class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int mini=1e9;
        int n=time.size();
        for(int i=0;i<n;i++)  mini=min(mini,time[i]);
        
        long long l=1;
        long long r=(1LL* mini*totalTrips);
        long long res=0;
        while(l<=r){
          long long mid=(l+r)/2;
          long long trip_completed=0;
          for(int i=0;i<n;i++){
            trip_completed+=(mid/time[i]);
          }
          if(trip_completed>=totalTrips){
            res=mid;
            r=mid-1;
          }
          else{
            l=mid+1;
          }

        }

return res;
    }
};