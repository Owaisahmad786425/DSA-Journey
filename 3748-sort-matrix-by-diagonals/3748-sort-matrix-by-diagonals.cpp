class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            int row=i;
            int col=0;
            vector<int> store;
            while(row<n && col<n){
              store.push_back(grid[row][col]);
              row++;
              col++;
            }
            sort(store.begin(),store.end(),greater<int>());
            row=i;
            col=0;
            int index=0;
            while(row<n && col<n){
                grid[row][col]=store[index];
                row++;
                col++;
                index++;
            }
        }
        for(int j=1;j<n;j++){
            int row=0;
            int col=j;
              vector<int> store;
            while(row<n && col<n){
              store.push_back(grid[row][col]);
              row++;
              col++;
            }
            sort(store.begin(),store.end());
            row=0;
            col=j;
            int index=0;
            while(row<n && col<n){
                grid[row][col]=store[index];
                row++;
                col++;
                index++;
            }
        }
        return grid;
    }
};