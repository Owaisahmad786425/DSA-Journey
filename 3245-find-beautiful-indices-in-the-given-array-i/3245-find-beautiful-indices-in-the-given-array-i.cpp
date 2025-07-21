class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> indices_store;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i>(n-b.size())){
                break;
            }
            if(s.substr(i,b.size())==b){
                indices_store.push_back(i);
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(i>(n-a.size())) break;
            if(s.substr(i,a.size())==a && indices_store.size()>0){
                int low=0;
                int high=indices_store.size()-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(abs(i-indices_store[mid])<=k){
                        res.push_back(i);
                        break;
                    }
                    else if(i<indices_store[mid]){
                           high=mid-1;
                    }
                    else{
                    low=mid+1; 
                    }
                }
            }
        }
        return res;
    }
};