class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=-1e9;
        for(int i=0;i<n-2;i++){
           int sum=nums[i]+nums[i+1];
            int idx=i+2;
            bool flag=0;
            while(idx<n && nums[idx]<sum){
                if(!flag) flag=1;
                idx++;
            }
            if(!flag) continue;
            else if(flag && idx==n){
                res=max(res,(sum+nums[idx-1]));
            }
            else{
                res=max(res,(sum+nums[idx-1]));
            }
        }
        if(res==-1e9) return 0;
        return res;
    }
};