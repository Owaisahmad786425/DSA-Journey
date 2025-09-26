class Solution {
public:
    int minSwaps(string s) {
      int size=0;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(size==0 && s[i]==']'){
                res++;
                size++;
            }

            else if(s[i]=='['){
                
                size++;
            }

            else if(s[i]==']')  size--;
        }
        return res;
    }
};