class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
       //use string as stack
       string store="";
       int res=0;
       string store2="";
       if(y>=x){
          for(int i=0;i<n;i++){
             if(store.size()>0 &&store.back()=='b' && s[i]=='a'){
                res+=y;
                store.pop_back();
             }
             else{
                store+=s[i];
             }
          }
          for(int i=0;i<store.size();i++){
            if(store2.size()>0&& store2.back()=='a' && store[i]=='b'){
                res+=x;
                store2.pop_back();
            }
            else{
                store2+=store[i];
            }
          }

       }
       else{
        for(int i=0;i<n;i++){
             if(store.size()>0 &&store.back()=='a' && s[i]=='b'){
                res+=x;
                store.pop_back();
             }
             else{
                store+=s[i];
             }
          }
          for(int i=0;i<store.size();i++){
            if(store2.size()>0&& store2.back()=='b' && store[i]=='a'){
                res+=y;
                store2.pop_back();
            }
            else{
                store2+=store[i];
            }
          }
       }

 return res;
    }
};