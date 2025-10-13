class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums),end(nums));
        long long count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
                int el=lower-nums[i];
                auto it=lower_bound(nums.begin()+(i+1),nums.end(),el);
                int idx1=it-nums.begin();
                it=upper_bound(nums.begin()+(i+1),nums.end(),upper-nums[i]);
                int idx2=it-nums.begin();
                count+=(idx2-idx1);
        }
        return count;
    }
};