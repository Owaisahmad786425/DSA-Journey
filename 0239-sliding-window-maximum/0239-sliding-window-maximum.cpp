class Solution {
    typedef pair<int,int> P;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     priority_queue<P> max_heap;
     //O(Klogk)
     for(int i=0;i<k;i++){
        max_heap.push({nums[i],i});
     }   
     vector<int> res;

     res.push_back(max_heap.top().first);
     //o(nlogn+nlogn)
     for(int i=k;i<nums.size();i++){
       int idx=max_heap.top().second;
       idx=(idx+k-1);
       if(i<=idx){
        max_heap.push({nums[i],i});
        res.push_back(max_heap.top().first);
       }
       else{
        while(!max_heap.empty() && idx<i){
            max_heap.pop();
          idx=max_heap.top().second;
             idx=(idx+k-1);
        }
         max_heap.push({nums[i],i});
        res.push_back(max_heap.top().first);
       }
     }

return res;
    }
};