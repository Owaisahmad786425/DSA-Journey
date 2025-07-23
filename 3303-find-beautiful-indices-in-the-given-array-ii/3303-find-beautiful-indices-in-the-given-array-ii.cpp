class Solution {
    vector<int> calculate_lps(string pat){
        int n=pat.size();
        vector<int> res(n);
        res[0]=0;
        int i=1,len=0;
        while(i<n){
          
            while(len>0 && pat[i]!=pat[len]){
               len=res[len-1];
            }
            if(pat[i]==pat[len]){
                len++;
            }
            res[i]=len;
            i++;
        } 
        
       return res; 
    }
    vector<int> populate(string check,string pat,vector<int> lps){
        vector<int> store;
        int i=0;
        int j=0;
        int n=check.size();
        while(i<n){
             if(check[i]==pat[j]){
                i++;
                j++;
                if(j==pat.size()){
                    store.push_back(i-pat.size());
                    j=lps[j-1];
                }
             }
             else if(check[i]!=pat[j] && j>0){
                j=lps[j-1];
             }
             else{
                i++;
             }
        }
        return store;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> lps1=calculate_lps(a);
        vector<int> lps2=calculate_lps(b);
        vector<int> indices_a=populate(s,a,lps1);
        vector<int> indices_b=populate(s,b,lps2);

        vector<int> ans;
      
        for(int i=0;i<indices_a.size();i++){
            int low=0;
            int high=indices_b.size()-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(abs(indices_a[i]-indices_b[mid])<=k){
                    ans.push_back(indices_a[i]);
                    break;
                }
                else if(indices_a[i]<indices_b[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return ans;
    }
};