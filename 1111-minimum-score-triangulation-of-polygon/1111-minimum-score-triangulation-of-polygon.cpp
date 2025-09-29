class Solution {

    int fun(vector<int> &values,int i,int j,vector<vector<int>> &dp){
        //base case
        if(j-i+1<3) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
        for(int k=i+1;k<j;k++){
            int score=fun(values,i,k,dp)+(values[i]*values[j]*values[k])+fun(values,k,j,dp);
            res=min(res,score);
        }
        return dp[i][j]=res;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(51,vector<int>(51,-1));
        return fun(values,0,n-1,dp);
        
   }
};