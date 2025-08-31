class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        ans[0]=nums[0];
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i];
        }
       int suffix=1;
       ans[n-1]=ans[n-2];
       suffix=nums[n-1];
       for(int i=n-2;i>0;i--){
        ans[i]=suffix*ans[i-1];
        suffix*=nums[i];
       }
       ans[0]=suffix;
       return ans;

    }
};