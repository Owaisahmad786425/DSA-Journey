class Solution {
    bool isValid(vector<int> &nums,int mid){
        vector<long long> arr(begin(nums),end(nums));
        for(int i=0;i<nums.size()-1;i++){
            if(arr[i]>mid) return false;
            else{
                long long buffer=mid-arr[i];
                arr[i+1]=arr[i+1]-buffer;
            }
        }
        return arr[nums.size()-1]<=mid;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        for(int i=0;i<n;i++) r=max(r,nums[i]);

        //BS on answers
     int res=0;
        while(l<=r){
            int mid=(l+r)/2;
                
            if(isValid(nums,mid)){
                res=mid;
                r=mid-1;
            }    
            else l=mid+1;
        }
        return res;
    }
};