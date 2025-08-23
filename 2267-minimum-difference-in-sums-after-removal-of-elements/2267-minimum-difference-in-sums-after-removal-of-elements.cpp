class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int size=nums.size();
        int n=size/3;
        vector<long long> prefix(size,0);
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>> min_heap;
        priority_queue<int> max_heap;
        for(int i=0;i<2*n;i++){
            sum+=nums[i];
            max_heap.push(nums[i]);

            if(max_heap.size()>n){
               sum-=max_heap.top();
               max_heap.pop();
            }
            prefix[i]=sum;
        }
        long long res=LLONG_MAX;
        sum=0;
        for(int i=size-1;i>=n;i--){
            sum+=nums[i];
            min_heap.push(nums[i]);

            if(min_heap.size()==n){
                res=min(res,(prefix[i-1]-sum));
                sum-=min_heap.top();
                min_heap.pop();
            }
        }
return  res;
    }
};