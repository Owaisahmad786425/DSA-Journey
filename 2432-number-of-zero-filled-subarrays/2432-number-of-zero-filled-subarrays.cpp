class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res=0;
        long long count_zero=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]!=0){
            res+=(count_zero*(count_zero+1))/2;
            count_zero=0;
            continue;
           }
     count_zero++;
        }
         res+=(count_zero*(count_zero+1))/2;
        return res;
    }
};