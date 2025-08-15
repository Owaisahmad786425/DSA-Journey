class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> mp(26);
        int n=s.size();
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
              for(int i=0;i<26;i++){
                if(mp[i].size()>0){
                    vis[mp[i].back()]=1;
                    mp[i].pop_back();
                    break;
                }
              }
              continue;
            }
            mp[s[i]-'a'].push_back(i);
        }
        string res="";
        for(int i=0;i<n;i++){
            if(!vis[i] && s[i]!='*'){
                res+=s[i];
            }
        }
        return res;
    }
};