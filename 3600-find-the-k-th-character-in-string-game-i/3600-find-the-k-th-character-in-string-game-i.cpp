class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
         while(word.size()<k){
            string temp=word;
            for(int i=0;i<word.size();i++){
                if(temp[i]=='z'){
                    temp[i]='a';
                    continue;
                }
                temp[i]=temp[i]+1;
            }
            word+=temp;
         }
         return word[k-1];
    }
};