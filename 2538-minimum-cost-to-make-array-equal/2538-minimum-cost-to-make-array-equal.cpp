class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=cost.size();
        int l=1;
        int r=0;
        for(auto it:nums){
            r=max(r,it);
        }
        long long res=0;
        while(l<=r){
            int mid=(l+r)/2;
            long long cost1=0;
            long long cost2=0;
            for(int i=0;i<n;i++){
                int operations=abs(mid-nums[i]);
                cost1+=(1LL*operations*cost[i]);
            }
             for(int i=0;i<n;i++){
                int operations=abs((mid+1)-nums[i]);
                cost2+=(1LL*operations*cost[i]);
            }
            if(cost1>cost2){
                res=cost2;
                l=mid+1;
            }
            else{
                res=cost1;
                r=mid-1;
            }
        }
        return res;
    }
};