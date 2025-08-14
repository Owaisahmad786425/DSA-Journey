class Solution {
    vector<int> generate_row(int n){
        long long store=1;
        vector<int> ans;
        ans.push_back(1);
        for(int col=1;col<n;col++){
            store*=(n-col);
            store/=(col);
            ans.push_back(store);
        }
        return ans;

    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> temp=generate_row(i+1);
        res.push_back(temp);
        }
        return res;
    }
};