class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int i=0;
        int j=0;
        while(i<n &&j<n){
            if(start[i]=='_' &&target[j]=='_'){
                i++;
                j++;
            }
            else if(start[i]!='_' && target[j]=='_'){
                j++;
            }
            else if(start[i]=='_' && target[j]!='_'){
                i++;
            }
            else{
                if(start[i]!=target[j]){
                    return false;
                }
                else{
                    if(start[i]=='R' && j<i){
                        return false;
                    }
                    else if(start[i]=='L' && j>i){
                        return false;
                    }
                    i++;
                    j++;
                }
            }
        }
         while(i<n){
            if(start[i]!='_') return false;
            i++;
         }
         while(j<n){
            if(target[j]!='_') return false;
            j++;
         }
        return true;
    }
};