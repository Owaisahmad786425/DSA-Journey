class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=-1e9;
        for(int i=0;i<n;i++){
            r=max(r,piles[i]);
        }
        int res=1e9;
        while(l<=r){
          int mid=(l+r)/2;

          long long hours=0;
          for(int i=0;i<n;i++){
            hours+=(piles[i]/mid);
            if(piles[i]%mid!=0) hours+=1;
          }
          if(hours<=h){
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