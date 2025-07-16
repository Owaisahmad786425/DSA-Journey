class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int odd_count=0;
        int even_count=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even_count++;
            }
            else{
                odd_count++;
            }
        }
      bool flag;
      if(nums[0]%2==0){
        flag=0;
      }
      else{
        flag=1;
      }
      int even_odd_count=1;
      for(int i=1;i<n;i++){
        if(flag==1 && nums[i]%2==0){
            flag=0;
            even_odd_count++;
        }
        else if(flag==0 && nums[i]%2!=0){
            flag=1;
            even_odd_count++;
        }
      }
      return max(even_count,max(odd_count,even_odd_count));
    }
};