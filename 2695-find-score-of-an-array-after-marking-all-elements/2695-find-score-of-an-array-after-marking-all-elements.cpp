class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        for(int i=0;i<n;i++){
            min_heap.push({nums[i],i});
        }
        int res=0;
        while(!min_heap.empty()){
            pair<int,int> store=min_heap.top();
            min_heap.pop();
            if(vis[store.second]) continue;

            res+=store.first;
            vis[store.second]=1;
            int left_idx=store.second+1;
            int right_idx=store.second-1;
            if(left_idx>=0 && left_idx<n) vis[left_idx]=1;
            if(right_idx>=0 && right_idx<n) vis[right_idx]=1;
           
        }
        return res;
    }
};