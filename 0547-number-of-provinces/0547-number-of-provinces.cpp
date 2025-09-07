class Solution {
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n=isConnected.size();
      vector<vector<int>> adj(n);
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
            }
        }
      }  
      vector<bool> visited(n,0);
      int res=0;
      for(int i=0;i<n;i++){
        if(!visited[i]){
            res++;
            dfs(i,adj,visited);
        }
      }
      return res;
    }
};