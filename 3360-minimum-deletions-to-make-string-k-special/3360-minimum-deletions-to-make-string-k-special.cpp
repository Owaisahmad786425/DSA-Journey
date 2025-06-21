class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        int res=1e9;
        for(int i=0;i<26;i++){
            if(freq[i]==0){
                continue;
            }
            int fix=freq[i];
            int count=0;
           for(int j=0;j<26;j++){
            if(freq[j]==0 || fix==freq[j]){
                continue;
            }
             if(freq[j]<fix){
                count+=freq[j];
             }                        
            else if(fix+k<freq[j]){
                count+=freq[j]-(fix+k);
            }
            
           }
           res=min(res,count);
        }
        return res;
    }
};