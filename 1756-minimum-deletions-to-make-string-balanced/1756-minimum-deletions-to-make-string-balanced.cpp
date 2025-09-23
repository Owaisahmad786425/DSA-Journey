class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            else if(!st.empty() && st.top()=='b' && s[i]=='a'){
                st.pop();
                res++;
            }
            else{
                st.push(s[i]);
            }
        }
        return res;
    }
};