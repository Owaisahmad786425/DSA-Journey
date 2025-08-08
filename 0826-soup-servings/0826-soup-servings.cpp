class Solution {
    double solve(int A,int B,vector<vector<double>> &dp){
        if(A<=0 && B<=0){
            return 0.5;
        }
        if(A<=0){
            return 1;
        }
        if(B<=0){
            return 0.0;
        }
    if(dp[A][B]!=-1) return dp[A][B];
       double one= solve(A-100,B-0,dp);
        double two=solve(A-75,B-25,dp);
        double three=solve(A-50,B-50,dp);
        double four=solve(A-25,B-75,dp);

        return dp[A][B]=(0.25*(one+two+three+four));
    }
public:
    double soupServings(int n) {
        if(n>=5000) return 1; 
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1.0));
        return solve(n,n,dp);
    }
};