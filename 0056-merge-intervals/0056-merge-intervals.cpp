class Solution {
    static bool comp(vector<int> v1,vector<int> v2){
        return v1[0]<v2[0];
    }
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
         int l=0;
         int i=0;
         vector<vector<int>> res;
         while(i<n){
            int maxi=intervals[i][1];
            while(i<n-1 &&maxi>=intervals[i+1][0]){
                maxi=max(maxi,intervals[i+1][1]);
                i++;
            }
            res.push_back({intervals[l][0],maxi});
            l=i+1;
            i=l;
         }
         return res;
    }
};