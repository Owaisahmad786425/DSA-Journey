class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int l=1;
        int r=1e7;
        int res=-1;
        while(l<=r){
            int mid=(l+r)/2;
            double time=0;
            for(int i=0;i<n;i++){
                if(i==n-1){
                  double store=(double)dist[i]/(double)mid;
                  time+=store;
                continue;
                   }
                time+=ceil((double)dist[i]/(double)mid);
            }

            if(time>hour){
                l=mid+1;
            }
            else{ 
                res=mid;
            r=mid-1;
            }
        }
        return res;
    }
};