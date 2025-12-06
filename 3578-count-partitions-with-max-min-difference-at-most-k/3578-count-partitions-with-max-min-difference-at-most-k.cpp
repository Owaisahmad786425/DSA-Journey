class Solution {
    const int M=1e9+7;
public:
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        vector<int> prefix(n+1,0);
        dp[0]=1;
        prefix[0]=1;
        deque<int> mindequeue,maxdequeue;
        int i=0;
        int j=0;
        while(j<n){
            while(!maxdequeue.empty()&&nums[j]>nums[maxdequeue.back()]) maxdequeue.pop_back();
           
           maxdequeue.push_back(j);

           while(!mindequeue.empty() && nums[j]<nums[mindequeue.back()]) mindequeue.pop_back();

           mindequeue.push_back(j);

           //invalid window 

           while(i<=j && nums[maxdequeue.front()]-nums[mindequeue.front()]>k){
            i++;
            if(!maxdequeue.empty() && maxdequeue.front()<i) maxdequeue.pop_front();

            if(!mindequeue.empty() && mindequeue.front()<i) mindequeue.pop_front();
           }
dp[j+1] = ( (prefix[j] - (i > 0 ? prefix[i-1] : 0) ) % M + M ) % M;

           prefix[j+1]=(prefix[j]+dp[j+1])%M;
           j++;
        }
 return dp[n];
    }
};