class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
             st.push(i);
            }
            else if(!st.empty() && s[i]==')') st.pop();
            else if(st.empty()){
                res++;
            }
        }
        res+=st.size();
        return res;
    }
};