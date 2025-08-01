class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);
        for(auto &it:words2){
            vector<int> temp_freq(26,0);
            int i=0;
            while(i<it.size()){
                temp_freq[it[i]-'a']++;
                i++;
            }

            for(int i=0;i<26;i++){
                freq[i]=max(freq[i],temp_freq[i]);
            }
        }
     
        vector<string> res;
       
        for(auto &it:words1){
             vector<int> check_freq(26,0);
             for(int i=0;i<it.size();i++){
                check_freq[it[i]-'a']++;
             }
             bool flag=0;
             for(int i=0;i<26;i++){
                if(freq[i]==0) continue;
                
                if(check_freq[i]<freq[i]){
                    flag=1;
                    break;
                }
             }
             if(!flag) res.push_back(it);
        }
        return res;
    }
};