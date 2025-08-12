class Solution {
    const int MOD=1e9+7;
    int solve(int idx,int n,int x, int size,int sum,vector<int> &vec,vector<vector<int>> &dp){
           if(sum==n){
            return 1;
           }
           if(idx>=size || sum>n){
            return 0;
           }
          if(dp[idx][sum]!=-1) return dp[idx][sum];

           int take=solve(idx+1,n,x,size,sum+pow(vec[idx],x),vec,dp);
           int not_take=solve(idx+1,n,x,size,sum,vec,dp);

           return dp[idx][sum]=(take+not_take)%MOD;
    }
public:
    int numberOfWays(int n, int x) {
        vector<int> vec;
        for(int i=1;i<=n;i++){
            if(pow(i,x)>n) break;

            vec.push_back(i);
        }
int sum=0;
vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,x,vec.size(),sum,vec,dp);
    }
};