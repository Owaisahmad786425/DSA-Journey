class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> st(nums.begin(), nums.end());
              int res=0;
       for(auto num:st){
        if(st.find(num-1)==st.end()){
            int numm=num;
            int cnt=0;
            while(st.find(numm)!=st.end()){
                numm+=1;
                cnt++;
            }
            res=max(res,cnt);
        }
       }
        return res;
    }
};