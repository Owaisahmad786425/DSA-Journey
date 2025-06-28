class Solution {
public:
    bool repeatedSubstringPattern(string s) {
 //gadha kahi ka 
 int n=s.size();
 for(int len=1;len<=n/2;len++){
    if(n%len==0){
      int times=n/len;
      string pat=s.substr(0,len);
      string check="";
      while(times>0){
        check+=pat;
        times--;
      }
      if(check==s){
        return true;
      }
    }
 }
 return false;
    }
};