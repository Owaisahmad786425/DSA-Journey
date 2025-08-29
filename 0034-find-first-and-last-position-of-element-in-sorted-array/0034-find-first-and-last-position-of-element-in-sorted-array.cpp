class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
       if(n==0) return{-1,-1};
       int l=0;
       int h=n-1;
       int idx1=-1,idx2=-1;
       while(l<=h){
        int mid=(l+h)/2;
        if(nums[mid]==target){
            idx1=mid;
            h=mid-1;
        }
        else if(nums[mid]<target) l=mid+1;
        else if(nums[mid]>target) h=mid-1;
       }
       idx2=idx1;
       l=0;
       h=n-1;
       while(l<=h){
          int mid=(l+h)/2;
          if(nums[mid]==target){
            idx2=mid;
            l=mid+1;
          }
            else if(nums[mid]<target) l=mid+1;
        else if(nums[mid]>target) h=mid-1;
       }
       return {idx1,idx2};
    }
};