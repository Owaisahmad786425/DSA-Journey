class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int res=0;
        for(int i=0;i<26;i++){
        if(freq[i]==0) continue;
         if(freq[i]%2==0) res+=2;
         else{
            res+=1;
         } 
        }
        return res;
    }
};