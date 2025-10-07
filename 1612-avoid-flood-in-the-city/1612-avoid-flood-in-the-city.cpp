class Solution {
    // int binary_search(int idx,vector<int> &zero_idx_s){
    //    int res=-1;
    //    int l=0;
    //    int r=zero_idx_s.size();
    //    while(l<=r){
    //     int mid=(l+r)/2;
    //     if(idx<zero_idx_s[mid]){
    //         res=zero_idx_s[mid];
    //         r=mid-1;
    //     }
    //     else l=mid+1;
    //    }
    //    return res;
    // }
public:
    vector<int> avoidFlood(vector<int>& rains) {
          unordered_map<int,int> mp;
          set<int> zero_idx_s;
          int n=rains.size();
          vector<int> ans(n);
           vector<bool> visited(n,0);
          for(int i=0;i<n;i++){
            if(rains[i]==0){
                zero_idx_s.insert(i);
                continue;
            }
            if(mp.find(rains[i])!=mp.end()){
                int last = mp[rains[i]];
                    auto it = zero_idx_s.upper_bound(last);
                    if (it == zero_idx_s.end()) return {}; 
                    ans[*it] = rains[i]; 
                    zero_idx_s.erase(it);
                    ans[i]=-1;
                    mp[rains[i]]=i;
            }
          
          else{
            mp[rains[i]]=i;
            ans[i]=-1;
          }
          }
          int index=0;
          while(rains[index]==0) index++;
          for(int i=0;i<n;i++){
            if(ans[i]==0) ans[i]=rains[index];
          }
          return ans;
    }
};