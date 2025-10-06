class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        if(p==0 || (p==1 && n==1)) return 0;
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums[n-1];
        int res;
        while(l<=r){
            int mid=(l+r)/2;
            int i=n-1;
            int count=0;
            while(i>0){
               if(abs(nums[i]-nums[i-1])<=mid) {
                count++;
                i-=2;
               }
               else i--;
            }

            if(count>=p){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};