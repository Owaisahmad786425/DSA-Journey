class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        int maxi=-1e9;
        int mini=1e9;
        int i=0;
        while(i<n){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
            if(maxi-mini>k){
                res++;
                maxi=-1e9;
                mini=1e9;
                continue;
            }
            i++;
        }
        return res+1;
    }
};