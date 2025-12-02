class Solution {
    typedef long long ll;
    bool check(long long val,vector<int>&batteries,int n){
        ll value=1LL*val*n;
        ll sum=0;
       int size=batteries.size();
       for(int i=0;i<size;i++){
        if(batteries[i]<val) sum+=batteries[i];
        else sum+=val;
       }

        if(sum>=value) return true;
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
       ll total=0;
       ll l=0;
     int size=batteries.size();
     for(int i=0;i<size;i++){
        total+=batteries[i];
     }
       ll r=total/n;
       long long res=0;
       while(l<=r){
        ll mid=(l+r)/2;

        if(check(mid,batteries,n)){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
       }
       return res;
    }
};