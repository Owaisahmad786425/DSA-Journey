class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int start=1e9;
       int end=-1e9;
        for(auto it:bloomDay){
            start=min(start,it);
            end=max(end,it);
        }
        int res=-1;
        while(start<=end){
            long long val=(start+end)/2;
            int cnt1=0;
            int cnt2=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=val){
                    cnt1++;
                }
               else if(bloomDay[i]>val && cnt1<k){
                cnt1=0;
                continue;
               }

               if(cnt1==k){
                cnt1=0;
                cnt2++;
               }
            }
            if(cnt2>=m){
                res=val;
                end=val-1;
            }
            else start=val+1;
        }
        return res;
    }
};