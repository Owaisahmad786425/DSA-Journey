class Solution {
    bool check(char a){
        if((a>=65 && a<=90)|| (a>=97 && a<=122)) return true;

        return false;
    }
    bool check2(char a){
        if(a>='0' && a<='9') return true;

        return false;
    }
public:
    bool isPalindrome(string s) {
        int low=0;
        int high=s.size()-1;
        while(low<=high){
            if(!isalnum(s[low]) && !isalnum(s[high])){
                high--;
                low++;
            }
            else if(!isalnum(s[low])) low++;
            else if(!isalnum(s[high])) high--;
            else if(check(s[low])&& check(s[high])){
                if(tolower(s[low])!=tolower(s[high])) return false;
                low++;
                high--;
            }
            else if(check2(s[low])&& check2(s[high])){
                if(s[low]!=s[high])return false;
                low++;
                high--;
            }
            else if((check2(s[low])&& check(s[high])) ||(check(s[low])&& check2(s[high]))) return false;
        }

        return true;
    }
};