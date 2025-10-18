class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
       nums[0]=nums[0]-k;
       int prv=nums[0];
       for(int i=1;i<n;i++){
        int lowest=nums[i]-k;
        int highest=nums[i]+k;
        if(lowest<=prv && prv+1<=highest){
            prv+=1;
            nums[i]=prv;
        }
        else if(lowest<=prv && prv+1>highest){
            nums[i]=min(prv,nums[i]);
        }
        else{
            nums[i]=lowest;
            prv=lowest;
        }
       }
       sort(begin(nums),end(nums));
       int cnt=1;
       for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]) continue;

        cnt++;
       }
       return cnt;
    }
};