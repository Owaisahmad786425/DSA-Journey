class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n=nums.size();
       unordered_map<int,int> mp;
       for(auto &it:nums){
        mp[it]++;
       } 
        priority_queue<pair<int,int>> max_heap;
        for(auto it:mp){
            max_heap.push({it.second,it.first});
        }
        vector<int> res;
        while(k>0){
          res.push_back(max_heap.top().second);
          max_heap.pop();
          k--;
        }
        return res;
    }
};