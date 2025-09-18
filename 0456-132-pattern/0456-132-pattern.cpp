class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int largest=INT_MIN;
        int s_largest=INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums[i]){
                s_largest=st.top();
                st.pop();
            }
            if(nums[i]<s_largest) return true;

            largest=nums[i];
            st.push(nums[i]);
        }
        return false;
    }
};