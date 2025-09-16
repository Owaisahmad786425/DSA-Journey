class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto num:asteroids){
            if(num>0 || st.empty()){
                st.push(num);
                continue;
            }
            bool flag=0;
            while(!st.empty() && st.top()>0 && abs(st.top())<=abs(num)){
                if(abs(st.top())==abs(num)){
                    st.pop();
                    flag=1;
                    break;
                }
                st.pop();
            }
      
            if(!flag && st.empty()) st.push(num);
            else if(!flag && !st.empty() && st.top()<0) st.push(num);

        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};