class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>nums[r]){
                if(nums[l]<=target && nums[mid]>target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else if(nums[mid]<nums[r]){
                if(nums[mid]<target && nums[r]>=target){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        if(r==l && nums[r]==target) return r;


        return -1;
    }
};