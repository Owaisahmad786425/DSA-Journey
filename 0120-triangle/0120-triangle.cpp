class Solution {
private:
int fun(int index1,int index2,vector<vector<int>> &triangle,int size,  vector<vector<int>> &dp){
    if(index2==size){
        return 0;
    }
    if(dp[index2][index1]!=-1){
        return dp[index2][index1];
    }
    int s1;
    int s2;
            s1=triangle[index2][index1]+fun(index1,index2+1,triangle,size,dp);
            

        s2=triangle[index2][index1]+fun(index1+1,index2+1,triangle,size,dp);

return dp[index2][index1]=min(s1,s2);
   
}

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
      vector<vector<int>> dp(m, vector<int>(m, -1));
        
  
        int res=fun(0,0,triangle,m,dp);
        return res;
    }
};