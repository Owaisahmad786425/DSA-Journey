class Solution {
    typedef pair<int,int> p;
    const int MOD=1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<p,vector<p>,greater<p>> min_heap;
      
        for(int i=0;i<n;i++){
           min_heap.push({nums[i],i});
        }

        int count=0;
        int left_half_sum=0;
      int total_sum=0;
        while(count<=right){
            count++;
            p store=min_heap.top();
            min_heap.pop();
            if(count<left){
                left_half_sum=(left_half_sum+store.first)%MOD;
                total_sum=(total_sum+store.first)%MOD;
            }
            else if(count<=right){
                total_sum=(total_sum+store.first)%MOD;
            }
            int idx=store.second;
            idx+=1;
            if(idx<n){
                min_heap.push({(store.first+nums[idx])%MOD,idx});
            }
        }
      return (total_sum-left_half_sum);
    }
};