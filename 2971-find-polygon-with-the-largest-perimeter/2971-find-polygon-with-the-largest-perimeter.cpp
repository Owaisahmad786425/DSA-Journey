class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n);
        sort(begin(nums),end(nums));
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
           prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=n-1;i>=2;i--){
            int actual_val=nums[i];
            int check_val=prefix[i-1];
            if(actual_val<check_val) return prefix[i];
        }
        return -1;
    }
};