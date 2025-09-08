class Solution {
public:
    string removeDuplicates(string s) {
        //use string as stack
        string res="";
        for(int i=0;i<s.size();i++){
            if(res==""){
                res.push_back(s[i]);
                continue;
            }
            if(res.back()==s[i]){
                res.pop_back();
            }
            else{
                res.push_back(s[i]);
                            }
        }
        return res;
    }
};