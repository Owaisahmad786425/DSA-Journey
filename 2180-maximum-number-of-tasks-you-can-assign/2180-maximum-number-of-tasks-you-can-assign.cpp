class Solution {
    bool check(vector<int> &tasks,vector<int> &workers,int pills,int strength,int mid){
         multiset<int> st(begin(workers),begin(workers)+mid);
         for(int i=mid-1;i>=0;i--){
            int reqrd=tasks[i];
            auto it=prev(st.end());

            if(*it>=reqrd) st.erase(it);
            else if(pills<=0) return false;

            else{
                auto weakestWorker=st.lower_bound(reqrd-strength);
                if(weakestWorker==st.end()) return false;

                st.erase(weakestWorker);
                pills--;
            }
           

         }
return true;

    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size();
        int m=workers.size();

        sort(begin(tasks),end(tasks));
        sort(begin(workers),end(workers),greater<int>());

        int l=0;
        int r=min(m,n);
        int res;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(tasks,workers,pills,strength,mid)){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return res;
    }
};