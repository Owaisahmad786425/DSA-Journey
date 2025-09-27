class Solution {
public:
    bool canBeValid(string s, string locked) {
        int open=0;
        int n=locked.size();
        if(n%2!=0) return false;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || locked[i]=='0'){
                open++;
            }
            else if(s[i]==')'){
                open--;
            }
            if(open<0) return false;
        }
        int close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || locked[i]=='0'){
                close++;
            }
            else if(s[i]=='('){
                close--;

            }
            if(close<0) return false;
        }
        return true;
    }
};