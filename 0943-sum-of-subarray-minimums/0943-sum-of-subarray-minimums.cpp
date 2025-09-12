class Solution {
    typedef pair<int,int> P;
    static bool comp(P p1, P p2){
      if(p1.first==p2.first) return p1.second<p2.second;
      return p1.first<p2.first;
    }
    const int MOD=1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n=arr.size();
       vector<P> vec;
       for(int i=0;i<n;i++){
        vec.push_back({arr[i],i});
       }
       sort(vec.begin(),vec.end(),comp);
       set<int> st;
       st.insert(-1);
       st.insert(n);
       int res=0;
    for(int i=0;i<n;i++){
        int idx=vec[i].second;
          st.insert(idx);
          auto var=st.find(idx);
          auto prv=prev(var);
          auto nxt=next(var);
          int l=*prv;
          int r=*nxt;
          int left=(idx-l)-1;
          int right=(r-idx);
          int no_of_subarrays=(right*left)+(right);
          res=(res+((1LL*no_of_subarrays*arr[idx])%MOD))%MOD;
    }
    return res;
       }
};