class Solution {
    typedef pair<int,int> P;
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<P> vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        vector<P> prefix(n);
        prefix[0]={nums[0],0};
        for(int i=1;i<n;i++){
            if(prefix[i-1].first<nums[i]){
                prefix[i]={nums[i],i};
                continue;
            }
            prefix[i]=prefix[i-1];
        }
        vector<P> temp_ans(n);
        int idx=-1;
        for(int i=0;i<n;i++){
            if(idx<vec[i].second){
                idx=vec[i].second;
            }
            temp_ans[vec[i].second]=prefix[idx];
        }

vector<int> ans(n,0);
for(int i=0;i<n;i++){
  int val=temp_ans[i].first;
  int index=temp_ans[i].second;
  ans[i]=max(ans[index],max(val,max(temp_ans[index].first,temp_ans[temp_ans[index].second].first)));
  
}
return ans;
    }
};