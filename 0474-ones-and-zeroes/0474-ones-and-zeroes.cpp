class Solution {
    int solve(vector<pair<int,int>> &count,int m,int n,int size,int idx,vector<vector<vector<int>>> &dp){
        if(count.size()<=idx || (m==0 &&n==0)) return 0;
         if(dp[m][n][idx]!=-1) return dp[m][n][idx];
        int take=0;
        if(count[idx].first<=m && count[idx].second<=n){
            take=1+solve(count,m-count[idx].first,n-count[idx].second,size,idx+1,dp);
        }

        int not_take=solve(count,m,n,size,idx+1,dp);

        return dp[m][n][idx]= max(take,not_take);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
   
    int size=strs.size();
     vector<pair<int,int>> count(size);
for(int i=0;i<size;i++){
    int zero_count=0;
    int one_count=0;
    for(auto it:strs[i]){
        if(it=='0') zero_count++;

        else one_count++;
    }
count[i]={zero_count,one_count};
}

vector<vector<vector<int>>> dp(101,vector<vector<int>>(101,vector<int>(601,-1)));
return solve(count,m,n,size,0,dp);
    }
};