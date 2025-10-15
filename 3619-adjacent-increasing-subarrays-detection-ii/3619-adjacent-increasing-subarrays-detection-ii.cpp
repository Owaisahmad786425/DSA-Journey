class Solution {
    bool check(vector<int> &nums,int n,int val){
        int cnt=1;
        int bp=0;
        for(int i=1;i<n;i++){
            if(cnt==(2*val)) return true;

            if(cnt==val && bp==0 && nums[i-1]>=nums[i]){
                bp++;
                cnt++;
            }
            else if(cnt<val && nums[i-1]>=nums[i]){
                cnt=1;
                bp=0;
            }
            else if(cnt>val && bp==0 && nums[i-1]>=nums[i]){
                cnt=val+1;
                bp=1;
            }
            else if(cnt>val && bp==1 && nums[i-1]>=nums[i]){
                cnt=1;
                bp=0;
            }
            else if(nums[i-1]<nums[i]) cnt++;
        }
        if(cnt==(2*val)) return true;
        return false;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        int r=(n/2);
        int res=1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(nums,n,mid)){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return res;
    }
};