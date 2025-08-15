class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int break_point=-1,swap_index=-1;
       int n=nums.size();
       for(int i=n-1;i>0;i--){
        if(nums[i]>nums[i-1]){
            break_point=i-1;
            break;
        }
       }
   if(break_point==-1) {
    reverse(nums.begin(),nums.end());
    return;
   }
    int mini=1e9;
    for(int i=break_point+1;i<n;i++){
        if(nums[break_point]<nums[i] && mini>nums[i]){
            swap_index=i;
            mini=nums[i];
        }
    }
    swap(nums[break_point],nums[swap_index]);
sort(nums.begin()+break_point+1,nums.end());

    }
};