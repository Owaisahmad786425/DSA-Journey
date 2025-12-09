class Solution {
    const int MOD=1e9+7;
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> left,right;
        left[nums[0]]++;
        int n=nums.size();
        for(int i=n-1;i>=1;i--){
            right[nums[i]]++;
        }
        int res=0;
        for(int i=1;i<n-1;i++){
            int value=(nums[i]*2);
            right[nums[i]]--;
            if(right[nums[i]]==0) right.erase(nums[i]);
            if(left.find(value)!=left.end() && right.find(value)!=right.end()){
                res=(res+(1LL*left[value]*right[value]))%MOD;
            }
            left[nums[i]]++;
        }
        return res;
    }
};