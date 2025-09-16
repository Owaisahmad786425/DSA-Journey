class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(st.empty()){
                st.push(nums[i]);
                i++;
                continue;
            }
             int num=nums[i];
            while(!st.empty() && i<n && gcd(num,st.top())>1){
                int var=lcm(num,st.top());
                st.pop();
                num=var;
            }
            st.push(num);
            i++;
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