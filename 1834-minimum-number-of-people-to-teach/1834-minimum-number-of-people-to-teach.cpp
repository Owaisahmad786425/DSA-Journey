class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int,int> freq;
        int m=languages.size();
        vector<bool> vis(m,0);
        vector<int> sad_users;
        for(int i=0;i<friendships.size();i++){
            unordered_set<int> st;
            int u=friendships[i][0];
            int v=friendships[i][1];
            for(int j=0;j<languages[u-1].size();j++){
                st.insert(languages[u-1][j]);
            }
            bool flag=0;
            for(int j=0;j<languages[v-1].size();j++){
                if(st.find(languages[v-1][j])!=st.end()){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                if(!vis[u-1]){
                vis[u-1]=1;
                sad_users.push_back(u-1);
                }
                if(!vis[v-1]){
                    vis[v-1]=1;
                sad_users.push_back(v-1);
                }
            }
        }
        for(int i=0;i<sad_users.size();i++){
           for(int j=0;j<languages[sad_users[i]].size();j++){
            freq[languages[sad_users[i]][j]]++;
           }
        }
        int maxi=0;
        for(auto it:freq){
            maxi=max(maxi,it.second);
        }
        return sad_users.size()-maxi;
    }
};