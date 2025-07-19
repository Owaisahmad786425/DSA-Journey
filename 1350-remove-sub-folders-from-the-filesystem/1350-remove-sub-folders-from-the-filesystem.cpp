class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        sort(folder.begin(),folder.end());
        string check="";
        vector<string> res;
        for(int i=0;i<n;i++){
            if(check==""){
                res.push_back(folder[i]);
                check=folder[i];
                continue;
            }
            int len=check.size();
            if(folder[i].substr(0,len)==check && folder[i].size()>len){
                if(folder[i][len]!='/'){
                res.push_back(folder[i]);
                check=folder[i];
                }
            }
            else if(folder[i].substr(0,len)!=check){
                res.push_back(folder[i]);
                check=folder[i];
            }
            
        }
        return res;
    }
};