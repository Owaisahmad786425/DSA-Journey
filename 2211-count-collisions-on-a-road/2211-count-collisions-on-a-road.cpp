class Solution {
public:
    int countCollisions(string directions) {
       int n=directions.size();
       stack<char> st;
       int res=0;
       for(int i=0;i<n;i++){
        if(directions[i]=='R') st.push(directions[i]);
        else if(st.empty() && (directions[i]=='R'|| directions[i]=='S')) st.push(directions[i]);
        else if(st.empty() && directions[i]=='L') continue;
        else if(!st.empty() && directions[i]=='L'){
            if(st.top()=='S') res+=1;
            else{
                char ch='S';
                res+=2;
                st.pop();
                while(!st.empty() && st.top()=='R'){
                    res+=1;
                    st.pop();
                }
                st.push(ch);
            }
        }
        else if(!st.empty() && directions[i]=='S'){
            while(!st.empty() && st.top()=='R'){
                res+=1;
                st.pop();
            }
            st.push(directions[i]);
        }
       }
       return res;
    }
};