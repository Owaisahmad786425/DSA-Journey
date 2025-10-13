class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int lowest=1;
        int highest=0;
        for(auto it:quantities){
            highest=max(highest,it);
        }
        int res;
        while(lowest<=highest){
            int mid=(lowest+highest)/2;
            int cnt=0;
            for(int i=0;i<m;i++){
                if(quantities[i]%mid==0) cnt+=quantities[i]/mid;
                else  cnt=cnt+((quantities[i]/mid)+1);
            }
            if(cnt<=n){
                res=mid;
                highest=mid-1;
            }
            else lowest=mid+1;
        }
   return res;
    }
};