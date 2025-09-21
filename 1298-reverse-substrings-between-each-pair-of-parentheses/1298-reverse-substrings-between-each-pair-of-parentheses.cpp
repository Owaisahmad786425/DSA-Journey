class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=')' &&s[i]!='(') continue;

            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                reverse(s.begin()+st.top()+1,s.begin()+i);
                st.pop();
            }
        }
        string res="";
        for(auto ch:s){
            if(ch==')' || ch=='(') continue;
            res+=ch;
        }
        return res;
    }
};