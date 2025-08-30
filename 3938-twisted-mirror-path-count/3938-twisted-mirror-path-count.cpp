class Solution {
    const int MOD=1e9+7;
    int fun(int row,int col,char dir,vector<vector<int>>& grid,int n,int m,vector<vector<vector<int>>> &dp){
        //base case
         if(row>=m || row<0 || col>=n || col<0) return 0;
         if(row==m-1 && col==n-1) return 1;
         int d;
         if(dir=='$') d=2;
         if(dir=='R') d=0;
         if(dir=='D') d=1;
      if(dp[row][col][d]!=-1) return dp[row][col][d];
        int first=0;
        int second=0;
        int third=0;
        if(grid[row][col]==0){
            first=fun(row,col+1,'R',grid,n,m,dp);
            second=fun(row+1,col,'D',grid,n,m,dp);
        }
        else{
            if(dir=='R') third=fun(row+1,col,'D',grid,n,m,dp);
            else if(dir=='D') third=fun(row,col+1,'R',grid,n,m,dp);
        }
      return dp[row][col][d]=(first+second+third)%MOD;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        char dir='$';
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(3,-1)));
        return fun(0,0,dir,grid,n,m,dp);
    }
};