class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int k=1;k<numRows;k++){
            vector<int> temp(res.back().size()+1);
            vector<int> store;
            store=res.back();
            temp[0]=1;
            temp.back()=1;
            int i=0,j=1;
            int idx=1;
             while(j<store.size()){
                temp[idx]=store[i]+store[j];
                i++;
                j++;
                idx++;
             }
             res.push_back(temp);
        }
        return res;
    }
};