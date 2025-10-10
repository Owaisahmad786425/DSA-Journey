class Solution {
    typedef long long ll;
    bool check(vector<int>&nums,vector<long long> &prefix,int score,long long k){
        int l=0;
        int r=score-1;
        int n=nums.size();
        while(r<n){
            int mid=(l+r)/2;
            ll left_element=mid-l;
            ll right_element=r-mid;
            ll left_val=(left_element*nums[mid]);
            ll right_val=(right_element*nums[mid]);

            ll actual_left_val=0;
            ll actual_right_val=0;
              if(l-1>=0){
                actual_left_val=(prefix[mid-1]-prefix[l-1]);
              }
              else if(mid-1>=0){
                actual_left_val=(prefix[mid-1]);
              }
            
        actual_right_val = prefix[r] - prefix[mid];

           ll operations = (left_val - actual_left_val) + (actual_right_val - right_val);

            if(operations<=k) return true;
           
           l++;
           r++;
        }
        return false;
    }
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n=nums.size();
        int min_score=1;
        int max_score=n;
        // unordered_map<int,int> mp;
        //   int res1=-1e9;
        // for(auto it:nums){
        //   mp[it]++;
        //   res1=max(res1,mp[it]);
        // }
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int res;
      while(min_score<=max_score){
        int score=(min_score+max_score)/2;
        if(check(nums,prefix,score,k)){
            res=score;
            min_score=score+1;
        }

else{
    max_score=score-1;
}
      }

      return res;

    }
};