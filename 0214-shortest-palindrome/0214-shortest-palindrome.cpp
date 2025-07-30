class Solution {
    vector<int> calculate_lps(vector<int> &lps,string res){
        lps[0]=0;
       int len = 0;
        int i = 1;
        while (i < res.size()) {
            if (res[i] == res[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
public:
    string shortestPalindrome(string s) {
             string rev=s;
             int n=s.size();
        reverse(rev.begin(),rev.end());
        string res=s+'-'+rev;
        vector<int> lps(res.size());
        lps=calculate_lps(lps,res);
        return rev.substr(0,n-lps[res.size()-1])+s;
    }
};