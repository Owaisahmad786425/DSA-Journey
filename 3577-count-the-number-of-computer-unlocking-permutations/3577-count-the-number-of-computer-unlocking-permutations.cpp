class Solution {
   const int MOD=1e9+7;
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        int mini=complexity[0];
        for(int i=1;i<n;i++){
            if(mini>=complexity[i]) return 0;

            mini=min(mini,complexity[i]);
        }

        int fact=1;
        for(int i=1;i<n;i++){
            fact=( (long long)fact * i ) % MOD;
        }
        return fact;
    }
};