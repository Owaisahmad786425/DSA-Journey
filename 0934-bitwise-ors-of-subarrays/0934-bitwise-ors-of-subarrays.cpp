class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> res;
        int n=arr.size();
        for(int i=0;i<n;i++){

            for(auto &it:prev){
                curr.insert(arr[i]|it);
                res.insert(arr[i]|it);
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev=curr;
            curr.clear();
        }
        return res.size();
    }
};