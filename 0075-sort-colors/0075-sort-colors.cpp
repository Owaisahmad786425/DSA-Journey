class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int r=n-1;
        int counter=0;
        while(counter<=r){
           if(nums[counter]==1){
            counter++;
           }
           else if(nums[counter]==0){
            swap(nums[counter],nums[left]);
            counter++;
            left++;
           }
           else{
            swap(nums[counter],nums[r]);
               r--;
           }
        }
    }
};