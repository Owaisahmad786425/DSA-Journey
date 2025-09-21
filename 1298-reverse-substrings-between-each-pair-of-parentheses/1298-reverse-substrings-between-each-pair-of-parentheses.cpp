class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        unordered_map<int,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='(' && s[i]!=')') continue;

            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
               mp[st.top()]=i;
               mp[i]=st.top();
               st.pop();
            }
        }

        string res="";
        int i=0;
        bool flag=0;
        while(i<n){
            if(s[i]=='(' || s[i]==')'){
                i=mp[i];
                flag=!flag;
            }
            else{
                res+=s[i];
            }

            if(!flag) i++;
            else{
                i--;
            }
        }
        return res;
    }
};