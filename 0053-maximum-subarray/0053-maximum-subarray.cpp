class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int res=-1e9;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            res=max(sum,res);
            if(sum<0) sum=0;
        }
        return res;
    }
};