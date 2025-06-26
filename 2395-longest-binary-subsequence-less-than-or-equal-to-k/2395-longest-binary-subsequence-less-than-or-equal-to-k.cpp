class Solution {
public:
    int longestSubsequence(string s, int k) {
        int binary_val;
        int n=s.size();
        int count=0;
        long long rem=k;
        for(int i=n-1;i>=0;i--){
              if(s[i]=='0'){
                count++;
                continue;
              }
             else{
                   if (rem >= 0) {
                    if (count <= 60) {
                        rem = rem - (long long)pow(2, count);
                    } else {
                        rem = -1;
                    }
                }

                if(rem>=0){
                    count++;
                }
             }
        }
        return count;
    }
};