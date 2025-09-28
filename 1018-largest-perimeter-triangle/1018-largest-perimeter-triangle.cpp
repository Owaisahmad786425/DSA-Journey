class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
         int idx=n-3;
         sort(nums.begin(),nums.end());
         bool flag=0;
         while(idx>=0 && nums[idx]+nums[idx+1]<=nums[idx+2]){
            idx--;
           
         }
         if(idx==-1) return 0;

         return (nums[idx]+nums[idx+1]+nums[idx+2]);
    }
};