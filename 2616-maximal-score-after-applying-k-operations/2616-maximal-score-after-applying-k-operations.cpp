class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for(auto &it:nums){
            max_heap.push(it);
        }
       long long res=0;
        while(k>0){
           double store=max_heap.top();
           max_heap.pop();
           res+=store;
           max_heap.push(ceil(store/3));
           k--;
       }
       return res;
    }
};