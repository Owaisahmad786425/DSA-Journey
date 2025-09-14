class Solution {
public:
    string removeStars(string s) {
       string res="";
        int n=s.size();
        for(auto ch:s){
            if(res=="" && ch=='*') continue;
            else if(res=="" && ch!='*'){
                res+=ch;
                continue;
            }
            else if(ch=='*') res.pop_back();
            else{
                res+=ch;
            }
        }
return res;
    }
};