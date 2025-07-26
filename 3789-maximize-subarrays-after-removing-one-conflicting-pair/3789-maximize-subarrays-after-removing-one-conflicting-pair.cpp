class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> store(n+1);
        for(auto &p: conflictingPairs){
             int a=min(p[0],p[1]);
             int b=max(p[0],p[1]);
             store[b].push_back(a);
        }
        int maxi=0;
        int second_maxi=0;
        long long what_to_add=0;
        long long res=0;
        vector<long long> extra(n+1);
        for(int end=1;end<=n;end++){
            
            for(auto &u:store[end]){
                if(u>=maxi){
                    second_maxi=maxi;
                    maxi=u;
                }
                else if(u>second_maxi){
                    second_maxi=u;
                }
            }
            res+=end-maxi;
            extra[maxi]+=maxi-second_maxi;
            what_to_add=max(what_to_add,extra[maxi]);
        }
        return res+what_to_add;
    }
};