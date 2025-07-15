class Solution {
    bool check(char a){
        if(a=='a' || a=='e'|| a=='i' || a=='o' ||a=='u' ) return true;

        return false;
    }
public:
    int beautifulSubstrings(string s, int k) {
        //brute will work because the constraints are very low
       int n=s.size();
       int res=0;
       for(int i=0;i<n;i++){
      int cnt1=0;
      int cnt2=0;
      for(int j=i;j<n;j++){
     if(check(s[j])){
        cnt1++;
     }
     else{
        cnt2++;
     }
     if(cnt1==cnt2  && (cnt1*cnt2)%k==0){
        res++;
     }
      }
       }
       return res;
    }
};