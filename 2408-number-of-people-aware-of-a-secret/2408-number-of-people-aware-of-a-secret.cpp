class Solution {
    const int MOD=1e9+7;
    vector<int> dp;
    int solve(int day,int delay,int forget){
        if(day==1) return 1;

        if(dp[day]!=-1) return dp[day];

        int res=0;
        for(int prev=day-forget+1;prev<=day-delay;prev++){
            if(prev>0) res=(res+solve(prev,delay,forget))%MOD;
        }
        return dp[day]=res;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
       int total=0;
       dp.assign(n+1,-1);

       for(int day=n-forget+1;day<=n;day++){
        if(day>0){
                 total=(total+solve(day,delay,forget))%MOD;
        }
       }
       return total;
    }
};