class Solution {
    const int MOD=1e9+7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){
             power.push_back(1<<i);
            }
        }
        vector<int> answer;
        for(int j=0;j<queries.size();j++){
            int start=queries[j][0];
            int end=queries[j][1];
            long product=1;
            for(int i=start;i<=end;i++){
               product=(product*power[i])%MOD;
            }
            answer.push_back(product);
        }
        return answer;
    }
};