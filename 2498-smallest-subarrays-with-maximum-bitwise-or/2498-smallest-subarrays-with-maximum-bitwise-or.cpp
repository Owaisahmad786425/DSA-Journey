class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        //i learned today that OR operator is ireversilble
      int n=nums.size();
      vector<int> ans(n);
      vector<int> set_bit(32,-1);
      for(int i=n-1;i>=0;i--){
        int end_index=i;
        for(int j=0;j<32;j++){
            if(set_bit[j]==-1 && (nums[i]&(1<<j))){
                set_bit[j]=i;
            }
            else if((nums[i]&(1<<j))){
                set_bit[j]=min(set_bit[j],i);
            }
            else if(set_bit[j]!=-1){
                end_index=max(end_index,set_bit[j]);
            }
            
        }
        ans[i]=end_index-i+1;
      }
return ans;
    }
};