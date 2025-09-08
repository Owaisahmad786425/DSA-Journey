class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        stack<int> st;
        long long res=0;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
                if(!st.empty()) res++;
            }
            st.push(i);
        }
        return res;
    }
};