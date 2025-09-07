class Solution {
    bool dfs(int node,vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &path_visited){
        visited[node]=true;
        path_visited[node]=true;
        for(auto it:adj[node]){
            if(path_visited[it]) return false;
            if(!visited[it]){
            if(!dfs(it,adj,visited,path_visited)) return false;
            }
        }
       path_visited[node]=false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
       for(int i=0;i<prerequisites.size();i++){
        int u=prerequisites[i][1];
        int v=prerequisites[i][0];
       adj[u].push_back(v);
       } 
       vector<bool> visited(numCourses,0);
       vector<bool> path_visited(numCourses,0);
       for(int i=0;i<numCourses;i++){
        if(!visited[i]){
            if(!dfs(i,adj,visited,path_visited)) return false;
        }
       }
       return true;
    }
};