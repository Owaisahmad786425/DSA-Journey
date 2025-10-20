class Solution {
    bool check(vector<int> &candies,int val,long long k,int n){
        long long child_got=0;
        for(int i=0;i<n;i++){
            child_got+=(candies[i]/val);
        }
        return child_got>=k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int high=1e9;
        int res=0;
        int n=candies.size();
        while(low<=high){
            int val=(low+high)/2;
            if(check(candies,val,k,n)){
                res=val;
                low=val+1;
            }
            else high=val-1;
        }
        return res;
    }
};