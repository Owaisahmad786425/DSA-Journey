class Solution {
    // bool dfs(int node,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &path_visited){
    //     visited[node]=true;
    //     path_visited[node]=true;
    //     for(auto it:adj[node]){
    //         if(path_visited[it]) return false;
    //         if(!visited[it]){
    //         if(!dfs(it,adj,visited,path_visited)) return false;
    //         }
    //     }
    //    path_visited[node]=false;
    //     return true;
    // }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
       for(int i=0;i<prerequisites.size();i++){
        int u=prerequisites[i][1];
        int v=prerequisites[i][0];
       adj[u].push_back(v);
       } 
    vector<int> in_degree(numCourses,0);
    for(int i=0;i<adj.size();i++){
        for(auto it:adj[i]){
          in_degree[it]++;
        }
    }
  queue<int> q;
      int count=0;
    for(int i=0;i<in_degree.size();i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }

  while(!q.empty()){
    int node=q.front();
    count++;
    q.pop();
    for(auto it:adj[node]){
      in_degree[it]--;
      if(in_degree[it]==0){
        q.push(it);
      }
    }
  }
  return count==numCourses;
    }
};