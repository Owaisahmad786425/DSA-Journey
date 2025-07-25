class Solution {
public:
    int maxSum(vector<int>& nums) {
        //itna asaan nhi h jitna soch rhe ho owais
        //utna hard bhi nhi hai owais bs thoda tricky hai
       unordered_map<int,int> mp;
       int res=0;
       int zerocnt=0;
       int maxi=-1e9;
       for(int i=0;i<nums.size();i++){
        if(nums[i]>0 && mp.find(nums[i])==mp.end()){
            res+=nums[i];
            mp[nums[i]]++;
        }
        else if(nums[i]==0){
            zerocnt++;
        }
        else{
            maxi=max(maxi,nums[i]);
        }
       } 
        if(res==0 && zerocnt==0){
            return maxi;
        }

        return res;
    }
};