class Solution {
public:
    int minChanges(string s) {
        int i=0;
        int res=0;
        int n=s.size();
        int cnt=0;
        while(i<n){
           char a=s[i];
           char b=s[i+1];
           if(a!=b){
            res++;
           }
           i+=2;
        }
        return res;
    }
};