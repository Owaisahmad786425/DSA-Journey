class Solution {
     int MOD=1e9+7;
     
    long long modPow(long long base, int exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        int left=0;
        int right=n-1;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
              res = (res + modPow(2, right - left)) % MOD;

                left++;
               
            }
            else{
                right--;
            }
        }
        return res;
    }
};