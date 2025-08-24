class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int zero_count=0;
        int l=0,r=0;
        int res=0;
        while(r<n){
              if(nums[r]==0) zero_count++;
           while(zero_count>1){
            if(nums[l]==0) zero_count--;
            l++;
           }
         
           res=max(res,r-l);
           r++;
        }
        return res;
    }
};