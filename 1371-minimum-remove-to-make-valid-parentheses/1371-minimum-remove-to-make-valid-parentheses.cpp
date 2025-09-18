class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        vector<bool> vis(n,0);
        stack<int> st;
        for(int idx=0;idx<n;idx++){
          if(s[idx]>='a' && s[idx]<='z') continue;
          
          if(s[idx]==')' &&st.empty()){
            vis[idx]=1;
          }
          else if(s[idx]==')'){
            st.pop();
          }
          else if(s[idx]=='('){
            st.push(idx);
          }
        }
        while(!st.empty()){
            vis[st.top()]=1;
            st.pop();
        }
        string res="";
        for(int i=0;i<n;i++){
            if(!vis[i]){
                res+=s[i];
            }
        }
        return res;
    }
};