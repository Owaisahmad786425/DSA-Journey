class Solution {
public:
    string removeKdigits(string num, int k) {
         string res;
         int n=num.size();
        for(int i=0;i<n;i++){
            while(res.size()>0&&res.back()>num[i] &&k>0){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        while(k>0){
            res.pop_back();
            k--;
        }
        if(res.size()==0) return "0";
        
       reverse(res.begin(),res.end());
       while(res.size()>0 && res.back()=='0') res.pop_back();
        if(res.size()==0) return "0";
       reverse(res.begin(),res.end());
        return res;
    }
};