class Solution {
    int binary_search1(vector<int> &starting,int val,int n){
       int l=0;
       int r=n-1;
       int res=-1;
       while(l<=r){
        int mid=(l+r)/2;
        if(starting[mid]<=val){
            res=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
       }
       return res;
    }
        int binary_search2(vector<int> &ending,int val,int n){
       int l=0;
       int r=n-1;
       int res=-1;
       while(l<=r){
        int mid=(l+r)/2;
        if(ending[mid]<val){
            res=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
       }
       return res;
    }
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        vector<int> starting;
        vector<int> ending;
        for(auto it:flowers){
            starting.push_back(it[0]);
            ending.push_back(it[1]);
        }        
        int m=people.size();
        vector<int> ans(m);
        sort(starting.begin(),starting.end());
        sort(ending.begin(),ending.end());
        for(int i=0;i<m;i++){
             int res1=binary_search1(starting,people[i],n);
             int res2=binary_search2(ending,people[i],n);
            ans[i]=(res1+1)-(res2+1);
        }
        return ans;
    }
};