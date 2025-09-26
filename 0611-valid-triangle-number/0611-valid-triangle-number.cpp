class Solution {
    int binary_search(vector<int> &nums,int l,int r,int sum){
        int k=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<sum){
                k=mid;
                l=mid+1;
            }
            else{

                r=mid-1;
            }
        }
        return k;
    }
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=0;
        if(n<3) return 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;

            for(int j=i+1;j<n;j++){
                int sum=nums[i]+nums[j];

                int k=binary_search(nums,j+1,n-1,sum);
                if(k!=-1){
                    res+=(k-j);
                }
            }
        }
        return res;
    }
};