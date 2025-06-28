class Solution {
    bool static comp(pair<int,int> p1,pair<int,int> p2){
        return p1.second<p2.second;
    }
    bool static comp1(pair<int,int> p1,pair<int,int> p2){
        return  p1.first<p2.first;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> store;
       for(int i=0;i<nums.size();i++){
        store.push_back({nums[i],i});
       }
       sort(store.begin(),store.end(),comp1);
        vector<pair<int,int>> res;
        int n=nums.size();
       int i=n-1;
       while(k>0){
        res.push_back({store[i].first,store[i].second});
        i--;
        k--;
       }
       int size=res.size();
        sort(res.begin(),res.end(),comp);
         vector<int> result;
         for(int j=0;j<size;j++){
            result.push_back(res[j].first);
         }
         return result;
    }
};