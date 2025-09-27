class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=(l+r)/2;

            bool isEven=false;
            if((r-mid)%2==0) isEven=true;

            if(nums[mid]==nums[mid+1]){
                if(isEven){
                    l=mid+2;
                }
                else{
                    r=mid-1;
                }
            }
            else{
                if(isEven){
                     r=mid;
                }
                else{
                 l=mid+1;  
                }
            }
        }
        return nums[r];
    }
};