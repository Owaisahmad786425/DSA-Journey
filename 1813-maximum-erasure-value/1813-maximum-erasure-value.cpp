class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_map<int,int> mp;
       int n=nums.size();
       int low=0;
       int high=0;
    int res=-1e9,sum=0;
       while(high<n){
        while(mp.find(nums[high]) !=mp.end()){
            sum-=nums[low];
            mp[nums[low]]--;
            if(mp[nums[low]]==0){
                mp.erase(nums[low]);
            }
            low++;
        }
          sum+=nums[high];
          mp[nums[high]]++;
          res=max(res,sum);
          high++;
       } 
       return res;
    }
};