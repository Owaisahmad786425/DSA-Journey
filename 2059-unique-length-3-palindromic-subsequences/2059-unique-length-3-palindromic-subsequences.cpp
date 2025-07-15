class Solution {
public:
    int countPalindromicSubsequence(string s) {
       vector<int> store_start_index(26,-1);
       vector<int> store_end_index(26,-1);
       int n=s.size();
      for(int i=0;i<n;i++){
        if(store_start_index[s[i]-'a']==-1){
            store_start_index[s[i]-'a']=i;
        }
      }
      for(int i=n-1;i>=0;i--){
        if(store_end_index[s[i]-'a']==-1){
            store_end_index[s[i]-'a']=i;
        }
      }
      //successfully stored starting and ending index
      int res=0;
      for(int i=0;i<26;i++){
        if(store_start_index[i]==-1 || store_end_index[i]==-1){
            //character not present
            continue;
        }
        int start=store_start_index[i];
        int end=store_end_index[i];
        bool flag=0;
        vector<bool> check(26,0);
        for(int j=start+1;j<end;j++){
            if(flag && s[j]-'a'==i){
                continue;
            }
            if(!flag && s[j]-'a'==i){
                flag=1;
                res++;
            }
            else if(!check[s[j]-'a']){
                check[s[j]-'a']=1;
                res++;
            }
        }
      }


return res;
          }
};