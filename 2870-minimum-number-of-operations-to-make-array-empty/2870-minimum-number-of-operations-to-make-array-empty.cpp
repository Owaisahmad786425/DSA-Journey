class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
     int res=0;
        for(auto it:mp){
            int val=it.second;
            if(val==1) return -1;

            if(val%3==0) res+=(val/3);
            else if(val%3==1){
                val-=4;
                res+=(val/3);
                res+=2;
            }
            else{
                val-=2;
                res+=(val/3);
                res+=1;
            }
        }
        return res;
    }
};