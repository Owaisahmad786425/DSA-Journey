class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int> digits(10);
        for(int i=0;i<n;i++){
           digits[s[i]-'0']=i;
        }
        for(int i=0;i<n;i++){
            bool flag=0;
            for(int j=9;j>=0;j--){
                if(s[i]<j+'0' && digits[j]>i){
                    swap(s[i],s[digits[j]]);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        return stoi(s);
    }
};