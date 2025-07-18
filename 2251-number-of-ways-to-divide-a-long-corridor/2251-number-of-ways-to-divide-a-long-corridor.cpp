class Solution {
    const int MOD=1e9+7;
public:
    int numberOfWays(string corridor) {
        int cnt=0;
        int n=corridor.size();
        int start=-1;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){

                cnt++;

                if(cnt==2){
                    start=i;
                }
            }
        }
        if(cnt%2!=0 || cnt==0){
            return 0;
        }
        int id1=-1;
        int id2=-1;
        cnt=1;
        int res=1;
        for(int i=start;i<n;i++){
            if(corridor[i]=='P'){
                continue;
            }
            cnt++;
            if(cnt%2==0){
                id1=i;
            }
            else{
                id2=i;
            }
            if(id1!=-1 && id2!=-1){
               
                res=(1LL* res*(id2-id1))%MOD;
                id1=-1;
                id2=-1;
            }
        }
       return res;

    }
};