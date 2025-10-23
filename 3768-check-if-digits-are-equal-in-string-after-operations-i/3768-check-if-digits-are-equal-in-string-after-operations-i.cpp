class Solution {
public:
    bool hasSameDigits(string s) {
        string str=s;
        while(str.size()>2){
            string store="";
            for(int i=0;i<str.size()-1;i++){
                store+=((str[i]-'0')+(str[i+1]-'0'))%10 +'0';
            }
            str=store;
        }
        return str[0]==str[1];
    }
};