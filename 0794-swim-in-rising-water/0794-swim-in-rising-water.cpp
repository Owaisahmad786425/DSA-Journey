class Solution {
    bool dfs(int row,int col,vector<vector<int>> &grid,vector<vector<bool>> &visited,vector<pair<int,int>> &dir,int n,int time){
        if(row==n-1 && col==n-1) return true;

        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int new_row=row+dir[i].first;
            int new_col=col+dir[i].second;
            if(new_row>=0 && new_col>=0 && new_row<n && new_col<n && !visited[new_row][new_col] && grid[new_row][new_col]<=time && dfs(new_row,new_col,grid,visited,dir,n,time)){
                return true;
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int l=0;
        int r=2500;
        int n=grid.size();
        vector<pair<int,int>> dir;
        dir={{0,1},{0,-1},{1,0},{-1,0}};
        int res;
        while(l<=r){
            int time=(l+r)/2;
            vector<vector<bool>> visited(n,vector<bool>(n,0));
            if(grid[0][0]<=time && dfs(0,0,grid,visited,dir,n,time)){
                res=time;
                r=time-1;
            }
            else if(grid[0][0]>time){
                l=time+1;
            }
            else l=time+1;

        }
        return res;
    }
};