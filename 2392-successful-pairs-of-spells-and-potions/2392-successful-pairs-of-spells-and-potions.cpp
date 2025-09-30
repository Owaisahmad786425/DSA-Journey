class Solution {
    int lower_bound(vector<int> &potions,int val,int l,int r,long long success){
        int idx=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if((long long)(1LL* potions[mid] * val)<success){
                l=mid+1;
            }
            else{
                idx=mid;
                r=mid-1;
            }
        }
        return idx;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> res(n);
        for(int i=0;i<n;i++){
           int val=spells[i];
           int index=lower_bound(potions,val,0,m-1,success);
           if(index==-1) res[i]=0;
           else res[i]=(m-index);
        }
        return res;
    }
};