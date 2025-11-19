class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(true){
            bool flag=0;
            for(int i=0;i<n;i++){
                if(nums[i]==original){
                    flag=1;
                    break;
                }
            }
            if(!flag) break;

            else original*=2;
        }
        return original;
    }
};