class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>> mp;
        int n=grid.size();
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int digonal=i-j;
            mp[digonal].push_back(grid[i][j]);
        }
        }
for(auto &it:mp){
    if(it.first>=0)sort(it.second.begin(),it.second.end(),greater<int>());
    else{
        sort(it.second.begin(),it.second.end());
    }
    reverse(it.second.begin(),it.second.end());
}
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int digonal=i-j;
                grid[i][j]=mp[digonal].back();
                mp[digonal].pop_back();
            }
        }
        return grid;

    }
};