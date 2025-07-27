class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                prefix[i]=nums[i-1];
            }
            else{
                prefix[i]=prefix[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=nums[i+1]){
                suffix[i]=nums[i+1];
            }
            else{
                suffix[i]=suffix[i+1];
            }
        }
        int res=0;
        for(int i=1;i<n-1;i++){
              if(nums[i]==nums[i-1]) continue;
              else{
                if((prefix[i]!=0 && suffix[i]!=0)&& ((nums[i]>prefix[i] && nums[i]>suffix[i]) || (nums[i]<prefix[i] &&nums[i]<suffix[i]))) res++;
              }

        }
        return res;
        
            }
};