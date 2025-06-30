class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
       int track=INT_MIN;
       int res=0;
       for(auto it: mp){
          if(track==INT_MIN){
            track=it.first;
          }
          else if(it.first-track==1){
      res=max(res,it.second+mp[track]);
          }
          track=it.first;
       }
       return res;
    }
};