class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> freq(26,0);
        for(auto ch:brokenLetters){
            freq[ch-'a']++;
        }
        int res=0;
        int j=0;
        while(j<text.size()){
            vector<int> temp_freq(26,0);
            while(j<text.size() && text[j]!=' '){
                temp_freq[text[j]-'a']++;
                j++;
            }
            bool flag=0;
             for(int i=0;i<26;i++){
                 if(temp_freq[i]>0 && freq[i]>0){
                    flag=1;
                    break;
                 }
              }
              if(!flag) res++;
              j++;
        }
          return res;
    }
};