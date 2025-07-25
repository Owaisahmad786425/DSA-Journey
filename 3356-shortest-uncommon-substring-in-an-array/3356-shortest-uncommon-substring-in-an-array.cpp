class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string,int> mp;
        for(int i=0;i<arr.size();i++){
            unordered_set<string> st;
            for(int j=0;j<arr[i].size();j++){
                string sub="";
                for(int k=j;k<arr[i].size();k++){
                   sub+=arr[i][k];
                   st.insert(sub);
                }
            }
            for(auto it:st){
                mp[it]++;
            }
        }
        int n=arr.size();
        vector<string> res(n);
        for(int i=0;i<arr.size();i++){
            string res_sub="";
            for(int j=0;j<arr[i].size();j++){
                string check="";
                for(int k=j;k<arr[i].size();k++){
                      check+=arr[i][k];
                      if(mp[check]==1){
                          if(res_sub=="") res_sub=check;
                          else if(res_sub.size()>check.size()){
                            res_sub=check;
                          }
                          else if(res_sub.size()==check.size() && res_sub>check){
                            res_sub=check;
                          }
                      }
                }
            }
            res[i]=res_sub;
        }
        return res;
    }
};