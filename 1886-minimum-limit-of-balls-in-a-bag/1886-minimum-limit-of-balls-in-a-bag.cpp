class Solution {
    bool valid(vector<int> &nums,int maxOperations,int val){
    int n=nums.size();
    long long op=0;
    for(int i=0;i<n;i++){
        if(nums[i]<=val) continue;

        int store=nums[i]-val;
        if(store%val!=0){
            op+=(1+(store/val));
        }
        else{
            op+=(store/val);
        }
    }
    if(op<=maxOperations) return true;

    return false;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int r=INT_MIN;
        for(auto it:nums) r=max(r,it);
        int res;
        while(l<=r){
            int val=(l+r)/2;

            if(valid(nums,maxOperations,val)){
                res=val;
                r=val-1;
            }
            else l=val+1;
        }
  return res;
    }
};