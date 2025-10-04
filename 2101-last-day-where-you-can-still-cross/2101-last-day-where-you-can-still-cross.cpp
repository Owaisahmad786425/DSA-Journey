class Solution {
    bool dfs(int n_row,int n_col,vector<vector<int>> &matrix,vector<vector<bool>> &visited,vector<pair<int,int>> &dir,int row,int col){
        if(n_row==row-1) return true;
         if(visited[n_row][n_col]) return false;
         visited[n_row][n_col]=1;
        for(int i=0;i<4;i++){
            int new_row=n_row+dir[i].first;
            int new_col=n_col+dir[i].second;
    if(new_row>=0 && new_col>=0 && new_row<row && new_col<col && !visited[new_row][new_col] && matrix[new_row][new_col]==0 && dfs(new_row,new_col,matrix,visited,dir,row,col)){
        return true;
    }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> matrix(row,vector<int>(col,0));
        int n=cells.size();
        int res;
        int l=0;
        int r=n-1;
         vector<pair<int,int>> dir;
            dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(l<=r){
            int mid=(l+r)/2;
            matrix.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
           for(int i=0;i<mid;i++){
             int r=cells[i][0];
             int c=cells[i][1];
             matrix[r-1][c-1]=1;
           }
          vector<vector<bool>> visited(row,vector<bool>(col,0));
          bool flag=0;
          for(int i=0;i<col;i++){
            if(!visited[0][i] && matrix[0][i]!=1 && dfs(0,i,matrix,visited,dir,row,col)){
                flag=1;
                break;
            }
          }
         if(!flag){
            r=mid-1;
         } 
         else{
            res=mid;
            l=mid+1;
         }
         
        }
        return res;
    }
};