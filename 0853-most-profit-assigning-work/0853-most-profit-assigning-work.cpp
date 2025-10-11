class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();
        sort(worker.begin(),worker.end());
        vector<pair<int,int>> store(n);
        for(int i=0;i<n;i++){
            store[i]={profit[i],difficulty[i]};
        }
        sort(store.begin(),store.end(),greater<pair<int,int>>());
        int prv=m;
        int res=0;
        for(int i=0;i<n;i++){
            int prof=store[i].first;
            int diff=store[i].second;
            auto it= lower_bound(worker.begin(),worker.end(),diff);
            if(it<worker.begin()+prv){
               int idx = it - worker.begin();
                int labour=(prv-idx);
                res+=(labour*prof);
                prv=idx;
            }
        }
        return res;
    }
};