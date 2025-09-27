class Solution {
    vector<int> fun(char a){
        if(a=='D') return {0,-1};
        else if(a=='U') return {0,1};
        else if(a=='L') return {-1,0};
        else{
            return {1,0};
        }
    }
public:
    int distinctPoints(string s, int k) {
        int n=s.size();
        if(n==k) return 1;
        vector<vector<int>> prefix(n,vector<int>(2));
         vector<vector<int>> suffix(n,vector<int>(2));
         vector<int> initial;
         initial={0,0};
         for(int i=0;i<n;i++){
            vector<int> get=fun(s[i]);
            initial={initial[0]+get[0],initial[1]+get[1]};
            prefix[i]=initial;
         }
              initial={0,0};
            for(int i=n-1;i>=0;i--){
            vector<int> get=fun(s[i]);
            initial={initial[0]+get[0],initial[1]+get[1]};
            suffix[i]=initial;
           }
        //main logic

        int r=k;
        int idx=-1;
        set<vector<int>> st;
        int res=0;
        while(r<n){
            if(idx==-1){
               vector<int> check={suffix[r][0],suffix[r][1]};
               if(st.find(check)==st.end()){
                st.insert(check);
                res++;
               }
                idx++;
            }
            else{
                vector<int> check;
                check={prefix[idx][0]+suffix[r][0],prefix[idx][1]+suffix[r][1]};
                if(st.find(check)==st.end()){
                    st.insert(check);
                    res++;
                }
                idx++;
            }
            r++;
        }
       vector<int> check={prefix[idx][0],prefix[idx][1]};
       if(st.find(check)==st.end()) res++;
       return res;

    }
};