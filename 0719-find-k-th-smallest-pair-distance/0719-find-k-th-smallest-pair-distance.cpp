class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int l=0;
        int r=(nums[n-1]-nums[0]);
        int res;
        while(l<=r){
            int mid=(l+r)/2;
            int i=0;
            int j=i+1;
            int cnt=0;
            while(j<n){
                while(i<j && nums[j]-nums[i]>mid){
                   i++;
                }
                
                    cnt+=(j-i);
                
                j++;
            }
            if(cnt>=k){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};