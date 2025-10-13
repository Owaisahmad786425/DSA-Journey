class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> store;
        store=words;
        for(auto &it:store){
            sort(begin(it),end(it));
        }
        vector<int> res;
        stack<string> st;
        int n=words.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(store[i]);
                res.push_back(i);
                continue;
            }
           if(store[i]!=st.top()){
           st.push(store[i]);
            res.push_back(i);
           }
        }
        vector<string> res2;
        for(auto it:res){
            res2.push_back(words[it]);
        }
        return res2;
    }
};