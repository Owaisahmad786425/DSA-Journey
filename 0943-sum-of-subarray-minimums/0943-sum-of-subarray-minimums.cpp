class Solution {
      stack<int> empty;
      const int MOD=1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> left(n);
        vector<int> right(n);
        //populate the left array
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
              left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            st.push(i);
        }
        //populate the right array
        st.swap(empty);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) right[i]=n;
            else if(!st.empty()) right[i]=st.top();
            st.push(i);
        }
    int res=0;
    for(int i=0;i<n;i++){
        int left_index=left[i];
        int right_index=right[i];
        int op=(i-left_index)*(right_index-i);
        res=(res+(1LL*op*arr[i]))%MOD;
    }
return res;
    }

};