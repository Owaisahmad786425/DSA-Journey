class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(begin(items),end(items));
        int n=queries.size();
        int m=items.size();
                vector<int> pricing;
        vector<int> prefix_max(m);
        prefix_max[0]=items[0][1];
        pricing.push_back(items[0][0]);
        for(int i=1;i<m;i++){
            prefix_max[i]=max(prefix_max[i-1],items[i][1]);
            pricing.push_back(items[i][0]);

        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
           auto it=upper_bound(begin(pricing),end(pricing),queries[i]);
           int idx=(it-pricing.begin());
           if(idx-1==-1){
            ans[i]=0;
           }
           else ans[i]=prefix_max[idx-1];
        }

return ans;
    }
};