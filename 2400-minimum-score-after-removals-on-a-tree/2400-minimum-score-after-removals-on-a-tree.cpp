class Solution {
    void dfs(int node,int parent,int &timer,vector<int> &in_time,vector<int> &out_time,vector<int> &XOR_compute,vector<int> &nums,unordered_map<int,vector<int>> &adj){
       XOR_compute[node]=nums[node];
       in_time[node]=timer;
       timer++;
       for(auto it:adj[node]){
        if(it!=parent){
            dfs(it,node,timer,in_time,out_time,XOR_compute,nums,adj);
            XOR_compute[node]^=XOR_compute[it];
        }
       }
       out_time[node]=timer;
       timer++;
    }

    bool is_ancestor(int u,int v,vector<int> &in_time,vector<int> &out_time){
        return in_time[v]>=in_time[u] && out_time[v]<=out_time[u];
    }
    int get_score(int a,int b,int c){
        int max_val=max(a,max(b,c));
        int min_val=min(a,min(b,c));
        return max_val-min_val;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> in_time(n,0);
        vector<int> out_time(n,0);
        vector<int> XOR_compute(n,0);
        int timer=0;
        dfs(0,-1,timer,in_time,out_time,XOR_compute,nums,adj);
        int res=1e9;
        for(int u=1;u<n;u++){
            for(int v=u+1;v<n;v++){
              int xor1;
              int xor2;
              int xor3;
              if(is_ancestor(u,v,in_time,out_time)){
                   xor1=XOR_compute[v];
                   xor2=XOR_compute[u]^XOR_compute[v];
                   xor3=XOR_compute[0]^ xor1 ^xor2;

              }
              else if(is_ancestor(v,u,in_time,out_time)){
                xor1=XOR_compute[u];
                xor2=XOR_compute[v] ^XOR_compute[u];
                xor3=XOR_compute[0] ^ xor1 ^xor2;
              }
              else{
                xor1=XOR_compute[u];
                xor2=XOR_compute[v];
                xor3=XOR_compute[0] ^ xor1 ^xor2; 
              }
              res=min(res,get_score(xor1,xor2,xor3));
            }
        }
        return res;
    }
};