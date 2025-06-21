class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=2;
        vector<vector<int>> res;
        while(r<n){
            if(abs(nums[l]-nums[r])>k){
                return {};
            }

            res.push_back({nums[l],nums[l+1],nums[r]});
            l+=3;
            r+=3;
        }
        return res;
    }
};