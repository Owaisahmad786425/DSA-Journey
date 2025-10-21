class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
       int maxEl=*max_element(begin(nums),end(nums));
        vector<int> prefix(maxEl+1,0);
        for(auto it:nums){
            prefix[it]++;
        }
        for(int i=1;i<=maxEl;i++){
            prefix[i]=prefix[i-1]+prefix[i];
        }
      int res=-1e9;
      for(int target=0;target<=maxEl;target++){
        if(prefix[target]==0) continue;

        int left=max(target-k,0);
        int right=min(maxEl,target+k);

        int total=prefix[right]-(left-1>0 ? prefix[left-1]:0);
        int targetcnt=prefix[target]-(target-1>0 ? prefix[target-1]:0);

        int need=total-targetcnt;
        int op=min(need,numOperations);

        res=max(res,op+targetcnt);         
      }
        return res;
    }
};