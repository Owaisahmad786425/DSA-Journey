class Solution {
    typedef pair<int,pair<int,int>> p;
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<p,vector<p>,greater<p>> min_heap;
        int m=heightMap.size();
        int n=heightMap[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            visited[0][i]=1;
            min_heap.push({heightMap[0][i],{0,i}});
        }
          for(int i=0;i<n;i++){
            visited[m-1][i]=1;
            min_heap.push({heightMap[m-1][i],{m-1,i}});
        }
        for(int i=0;i<m;i++){
            visited[i][0]=1;
            min_heap.push({heightMap[i][0],{i,0}});
        }
         for(int i=0;i<m;i++){
            visited[i][n-1]=1;
            min_heap.push({heightMap[i][n-1],{i,n-1}});
        }
        vector<pair<int,int>> dir;
        int res=0;
        dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!min_heap.empty()){
            p store=min_heap.top();
            int boundary=store.first;
            int row=store.second.first;
            int col=store.second.second;
            min_heap.pop();
           for(int i=0;i<4;i++){ 
            int n_row=row+dir[i].first;
            int n_col=col+dir[i].second;
            if(n_row>=0 && n_row<m && n_col>=0 && n_col<n && !visited[n_row][n_col]){
                 visited[n_row][n_col]=1;
                int diff=boundary-heightMap[n_row][n_col];
                res+=max(diff,0);
                min_heap.push({max(boundary,heightMap[n_row][n_col]),{n_row,n_col}});

            }
           }
        }
        return res;
    }
};