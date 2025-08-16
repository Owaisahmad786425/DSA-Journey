class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int i=0;
        while(i<s.size() && s[i]!='6'){
            i++;
        }
        if(i==s.size()) return stoi(s);

        s[i]='9';
        return stoi(s);
    }
};