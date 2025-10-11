class Solution {
    bool dfs(int row,int col,vector<vector<int>> &min_manhattan_distance,vector<vector<bool>> &visited1,int n,vector<pair<int,int>> &dir,int val){
        if(row<0 || col<0 || row>=n || col>=n){
            return false;
        }
        if(row==n-1 && col==n-1) return true;
        visited1[row][col]=1;
        for(int i=0;i<4;i++){
            int new_row=row+dir[i].first;
            int new_col=col+dir[i].second;
            if(new_row>=0 && new_col>=0 && new_row<n && new_col<n &&!visited1[new_row][new_col] && min_manhattan_distance[new_row][new_col]>=val && dfs(new_row,new_col,min_manhattan_distance,visited1,n,dir,val)){
                return true;
            }
        }
        return false;
        
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
         vector<vector<bool>> visited(n,vector<bool>(n,0)); 
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    visited[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        vector<vector<int>> min_manhattan_distance(n,vector<int>(n,0));
        vector<pair<int,int>> dir;
        dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<int,int> p=q.front();
                int row=p.first;
                int col=p.second;
                q.pop();
                for(int j=0;j<4;j++){
                    int new_row=row+dir[j].first;
                    int new_col=col+dir[j].second;
                    if(new_row>=0 && new_col>=0 && new_row<n && new_col<n &&!visited[new_row][new_col]){
                        visited[new_row][new_col]=1;
                        min_manhattan_distance[new_row][new_col]=min_manhattan_distance[row][col]+1;
                        q.push({new_row,new_col});
                    }
                }
            }
        }

        visited.assign(n,vector<bool>(n,0));
        int l=0;
        int r=n*n;
        int res=0;
        while(l<=r){
            int mid=(l+r)/2;
             vector<vector<bool>> visited1(n,vector<bool>(n,0));
            if(min_manhattan_distance[0][0]>=mid && dfs(0,0,min_manhattan_distance,visited1,n,dir,mid)){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
            
        }
        return res;
     
    }
};