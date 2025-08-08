class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int n=nums.size();
       unordered_map<int,int> mp;
       for(auto &it:nums){
        mp[it]++;
       } 
       vector<vector<int>> bucket(n+1);
      for(auto &[num,freq]:mp){
          bucket[freq].push_back(num);
      }
      vector<int> res;
      for(int i=n;i>=0;i--){
        for(auto it:bucket[i]){
             if(k==0){
                break;
            }
            res.push_back(it);
            k--;
        }
      }
      return res;
    }
};