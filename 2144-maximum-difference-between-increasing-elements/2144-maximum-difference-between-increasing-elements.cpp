class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int el=nums[0];
        int res=-1;
        for(int i=1;i<n;i++){
            if(nums[i]!=el)
            res=max(res,nums[i]-el);
            if(el>nums[i]){
                el=nums[i];
            }
        }
        return res;
    }
};