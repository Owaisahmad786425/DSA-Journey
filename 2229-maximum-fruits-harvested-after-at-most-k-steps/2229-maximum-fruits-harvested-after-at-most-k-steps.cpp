class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int size=1e6;
        vector<int> prefix(size,0);
        int val=k;
        for(auto it:fruits) prefix[it[0]]=it[1];

        for(int i=1;i<size;i++) prefix[i]=prefix[i-1]+prefix[i];
int res=0;
int l,r;
for(auto it:fruits){
    if(it[0]<=startPos && startPos-it[0]<=k){
        l=it[0];
        int op=k-(startPos-it[0]);
        op/=2;
        r=startPos+op;
        if(l==0) res=max(prefix[r],res);
        else res=max(prefix[r]-prefix[l-1],res);
    }
    }

for(auto it:fruits){
    if(it[0]>startPos && it[0]-startPos<=k){
        r=it[0];
        int op=k-(it[0]-startPos);
        op/=2;
        l=max(0,startPos-op);
         if(l==0) res=max(prefix[r],res);
        else res=max(prefix[r]-prefix[l-1],res);
    }
}
       return res;
    }
};