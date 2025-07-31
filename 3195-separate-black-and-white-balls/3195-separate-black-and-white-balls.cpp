class Solution {
public:
    long long minimumSteps(string s) {
        long long zero_count=0;
       long long res=0;
       int n=s.size();
       // i found the bug
       for(int i=n-1;i>=0;i--){
           if(s[i]=='0'){
            zero_count++;
            continue;
           }
           res+=zero_count;
       }
return res;

    }
};