class Solution {
    int MOD=1e9+7;
    int findPow(int val,int pow,int MOD){
            int res = 1;
        val = val % MOD;
        while (pow > 0) {
            if (pow % 2 != 0) {
                res = (1LL * res * val) % MOD;
            }
            val = (1LL * val * val) % MOD;
            pow /= 2;
        }
        return res;
    }
    int NCR(int up,int k,vector<int> &fact,vector<int> &fermant_fact){
      return (1LL * fact[up] * fermant_fact[up - k] % MOD * fermant_fact[k] % MOD) % MOD;

    }
public:
    int countGoodArrays(int n, int m, int k) {
        vector<int> fact(n+1,1);
        for(int i=1;i<=n;i++){
           fact[i] = (1LL * fact[i - 1] * i) % MOD;

        }

        vector<int> fermant_fact(n+1,1);
        for(int i=0;i<=n;i++){
            fermant_fact[i]=findPow(fact[i],MOD-2,MOD);
        }
  int result = NCR(n - 1, k, fact, fermant_fact);
        result = (1LL * result * m) % MOD;
        result = (1LL * result * findPow(m - 1, n - k - 1,MOD)) % MOD;

return result;
    }
};