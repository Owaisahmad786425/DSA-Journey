class Solution {
    void fun(unordered_map<int,int> &mp,int x,vector<int> &ans){
        priority_queue<pair<int,int>> max_heap;
        int res=0;
        for(auto it:mp){
            max_heap.push({it.second,it.first});
        }

        if(max_heap.size()<x){
            while(!max_heap.empty()){
            pair<int,int> store=max_heap.top();
            res+=(store.first*store.second);
            max_heap.pop();
            }
        }
        else{
            int count=0;
            while(count<x){
            pair<int,int> store=max_heap.top();
            res+=(store.first*store.second);
            max_heap.pop();
            count++;
            }
        }
        ans.push_back(res);
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int l=0;
        int r=k-1;
        for(int i=l;i<=r;i++) mp[nums[i]]++;
        vector<int> ans;

        while(r<n){
            fun(mp,x,ans);

            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            r++;
            if(r<n) mp[nums[r]]++;

        }
        return ans;
    }
};