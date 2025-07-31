class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;
        int n=str1.size();
        while(j<str2.size()&& i<n){
            if(str1[i]==str2[j]){
                i++;
                j++;
                continue;
            }
            if(str1[i]=='z'){
                str1[i]='a';
            }
            else{
                str1[i]=str1[i]+1;
            }
            if(str1[i]!=str2[j]){
                i++;
            }
            else if(str1[i]==str2[j]){
                j++;
                i++;
            }
             
        }
        return j==str2.size();
    }
};