class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int bound=nums[n-1];
        for(int x=0;x<=bound;x++){
            auto it = lower_bound(nums.begin(), nums.end(), x);
            int idx = it - nums.begin();
            if(n-idx==x) return x;

        }

        return -1;
    }
};