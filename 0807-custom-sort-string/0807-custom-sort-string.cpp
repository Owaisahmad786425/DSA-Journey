class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> hash(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
          hash[s[i]-'a']++;
        }
        int pointer=0;
        for(int i=0;i<order.size();i++){
            if(hash[order[i]-'a']>0){
                for(int j=0;j<hash[order[i]-'a'];j++){
                    s[pointer]=order[i];
                    pointer++;
                }
                hash[order[i]-'a']=0;
            }
        }

        for(int i=0;i<26;i++){
            if(hash[i]>0){
                for(int j=0;j<hash[i];j++){
                    s[pointer]=i+'a';
                    pointer++;
                }
            }
        }
        return s;
    }
};