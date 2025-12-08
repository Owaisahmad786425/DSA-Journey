class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int i=k;
        int j=k;
        int res=nums[k];
        int mini=nums[k];
        while(i>0 || j<n-1){
            int left_val=(i>0)?nums[i-1]:0;
            int right_val= (j<n-1)?nums[j+1]:0;
            if(left_val>=right_val){
                mini=min(mini,left_val);
               i--;
            }
            else{
                mini=min(mini,right_val);
                j++;
            }
            res=max(res,(mini*(j-i+1)));
        }
        return res;
    }
};