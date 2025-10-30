class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size()-1;
        stack<int> st;
        while(n>=0){
            st.push(n);
            n--;
        }
        int prev=0;
        int op=0;
        while(!st.empty()){
            while(!st.empty() && prev>=target[st.top()]){
                prev=target[st.top()];
                st.pop();
            }
            if(!st.empty()){
                op+=target[st.top()]-prev;
                prev=target[st.top()];
                st.pop();
            }
        }

        return op;

    }
};