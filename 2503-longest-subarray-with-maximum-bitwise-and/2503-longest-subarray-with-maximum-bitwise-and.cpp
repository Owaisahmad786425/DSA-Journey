class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_and=0;
        for(auto &it:nums){
            max_and=max(max_and,it);
        }
        int cnt=0;
        int res=0;
        for(auto &it:nums){
            if(it==max_and){
                cnt++;
                continue;
            }
            res=max(res,cnt);
            cnt=0;
        }
        res=max(res,cnt);
        return res;
    }
};