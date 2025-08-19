class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>>  table(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=0;j<strs[i].size();j++){
                freq[strs[i][j]-'a']++;
            }
            table[i]=freq;
        }
        map<vector<int>,vector<int>> hash_table;
        for(int i=0;i<n;i++){
            hash_table[table[i]].push_back(i);
        }
        vector<vector<string>> res;
        for(auto it:hash_table){
            vector<string> temp;
            for(int i=0;i<it.second.size();i++){
              temp.push_back(strs[it.second[i]]);
            }
            res.push_back(temp);
        }
        return res;
    }
};