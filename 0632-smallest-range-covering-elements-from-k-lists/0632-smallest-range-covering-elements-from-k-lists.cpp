class Solution {
    typedef pair<int,int> P;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int> vec(n,0);
        priority_queue<P,vector<P>,greater<P>> min_heap;
        priority_queue<int> max_heap;
        for(int i=0;i<n;i++){
            min_heap.push({nums[i][0],i});
            max_heap.push(nums[i][0]);
        }
        P res={1e9,1e9};
        while(true){
           P store=min_heap.top();
           int maxi=max_heap.top();
           min_heap.pop();
           P range={store.first,maxi};
           if((res.first==1e9 && res.second==1e9) || (range.second-range.first<res.second-res.first) ||(res.second-res.first==range.second-range.first && res.first>range.first)){
            res=range;
           }
           int list_no=store.second;
           vec[list_no]++;
           if(vec[list_no]>=nums[list_no].size()) break;
           int element=nums[list_no][vec[list_no]];
           min_heap.push({element,list_no});
           max_heap.push(element);
        }
        return {res.first,res.second};
    }
};