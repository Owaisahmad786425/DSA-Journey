class Solution {
    int fun(int index,int maxi,vector<int> &nums,int curr,int n){
            //base case;
            if(index>=n){
                return (curr==maxi)?1:0;
            }
           int not_take=fun(index+1,maxi,nums,curr,n);
           int take=fun(index+1,maxi,nums,curr|nums[index],n);
           return take+not_take;    
    }
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            maxi=maxi|nums[i];
        }
        sort(nums.begin(),nums.end());
          int curr=0;
        return fun(0,maxi,nums,curr,n);
      
    }
};