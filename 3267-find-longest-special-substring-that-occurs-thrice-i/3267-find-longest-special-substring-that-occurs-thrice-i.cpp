class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> special_freq;
        int n=s.size();
        for(int i=0;i<n;i++){
            string store_special="";
            for(int j=i;j<n;j++){
               if(s[i]!=s[j]) break;

               store_special+=s[j];
               special_freq[store_special]++;
            }
          
        }
        int res=-1;
        for(auto it:special_freq){
            if(it.second>=3 && res<(int)it.first.size()){
                res=it.first.size();
            }
        }
        return res;
    }
};