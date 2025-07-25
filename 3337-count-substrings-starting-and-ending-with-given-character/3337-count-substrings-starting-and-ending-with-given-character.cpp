class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n=s.size();
        long long  cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                cnt++;
            }
        }
        long long res=(cnt*(cnt+1))/2;

        return res;


    }
};