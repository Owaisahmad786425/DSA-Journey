class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
     int users=languages.size();
     int relations=friendships.size();
     int res=1e9;
     for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<relations;j++){
            int u=friendships[j][0];
            int v=friendships[j][1];
            bool flag=0;
            for(int k=0;k<languages[u-1].size();k++){
                if(i==languages[u-1][k]) {
                    flag=1;
                    break;
                }
            }
            if(!flag){
             count++;
                languages[u-1].push_back(i);
            }
            flag=0;
             for(int k=0;k<languages[v-1].size();k++){
                if(i==languages[v-1][k]) {
                    flag=1;
                    break;
                }
            }
             if(!flag){
                count++;
                languages[v-1].push_back(i);
             }
        }
        res=min(res,count);
     }

return res;
    }
};