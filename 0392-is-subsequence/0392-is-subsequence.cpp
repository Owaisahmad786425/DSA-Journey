class Solution {
public:
    bool isSubsequence(string s, string t) {
     //direct code kabhi nhi krna hai
     int n=t.size();
     int m=s.size();
     if(n==m &&s==t){
        return true;
     }
     int index=0;
     for(int i=0;i<n;i++){
        if(index<m && s[index]==t[i]){
            index++;
        }
        if(index>=m){
            return true;
        }
     }
     return false;
    }
};