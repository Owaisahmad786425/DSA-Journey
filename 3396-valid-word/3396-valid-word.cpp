class Solution {
    bool check(char a){
    if(a=='a'||a=='A'|| a=='e' || a=='E' || a=='i' || a=='I' || a=='o' || a=='O' || a=='u' || a=='U'){
        return true;
    }
    return false;
    }
 public:
    bool isValid(string word) {
        bool isvowel=0;
        bool isconsonent=0;
        int n=word.size();
        if(n<3){
            return false;
        }
        for(int i=0;i<n;i++){
            if(word[i]=='@' || word[i]=='#' || word[i]=='$'){
                return false;
            }
            else if(check(word[i])){
               isvowel=true;
            }
            else if(word[i]>='0' && word[i]<='9'){
              continue;
            }
            else{
                isconsonent=true;
            }
        }
        if(!isvowel || !isconsonent){
            return false;
        }
        return true;
    }
};