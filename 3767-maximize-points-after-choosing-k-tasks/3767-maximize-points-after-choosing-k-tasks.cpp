class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n=technique1.size();
        long long res=0;
        for(int i=0;i<n;i++){
            res+=technique1[i];
        }

        vector<int> delta;
        for(int i=0;i<n;i++){
            delta.push_back(technique2[i]-technique1[i]);
        }
        sort(begin(delta),end(delta),greater<int>());
        long long store=res;
        for(int i=0;i<(n-k);i++){
            store+=delta[i];
            res=max(res,store);
        }
        return res;
    }
};