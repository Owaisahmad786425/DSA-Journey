class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long N=nums.size();
        priority_queue<long long> max_heap;
        priority_queue<long long,vector<long long>,greater<long long>> min_heap;
        vector<long long> left_min(N,0),right_max(N,0);
        long long n=N/3;
        long long sum1=0;
        long long  sum2=0;
        //for left store it owais
        for(int i=0;i<N-n;i++){
            sum1+=nums[i];
            max_heap.push(nums[i]);
            if(max_heap.size()>n){
                sum1-=max_heap.top();
                max_heap.pop();
            }
            left_min[i]=sum1;
        }
        //for right store it owais
        for(int i=N-1;i>=n;i--){
            sum2+=nums[i];
            min_heap.push(nums[i]);
            if(min_heap.size()>n){
                sum2-=min_heap.top();
                min_heap.pop();
            }
            right_max[i]=sum2;
        }
        long long res=LLONG_MAX;  

        for(int i=n-1;i<N-n;i++){
            res=min(res,(left_min[i]-right_max[i+1]));
        }
        return res;

    }
};