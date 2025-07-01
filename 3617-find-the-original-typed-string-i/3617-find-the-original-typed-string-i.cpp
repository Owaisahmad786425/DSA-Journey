class Solution {
public:
    int possibleStringCount(string word) {
       int n=word.size();
       int count=1;
       int res=1;
       char track=word[0];
       for(int i=1;i<n;i++){
        if(word[i]!=track){
            res+=count-1;
            count=1;
            track=word[i];
            continue;
        }
         count++;
       }
       res+=count-1;
       return  res;
    }
};