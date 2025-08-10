class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int i=0;
        string s=to_string(n);
        sort(s.begin(),s.end());
        string check="";
        while(check.size()<=s.size()){
             check=to_string(1<<i);
            sort(check.begin(),check.end());
            if(s==check) return true;

            i++;
        }
        return false;
    }
};