class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int sum1=0;
        sum1+=nums[0];
        int sum2=0;
        for(int i=1;i<n;i++){
            sum2+=nums[i];
        }
        int cnt=0;
        if(abs(sum1-sum2)%2==0) cnt++;
        for(int i=2;i<n;i++){
             sum1+=nums[i-1];
             sum2-=nums[i-1];
             if(abs(sum1-sum2)%2==0) cnt++;
        }
        return cnt;
    }
};