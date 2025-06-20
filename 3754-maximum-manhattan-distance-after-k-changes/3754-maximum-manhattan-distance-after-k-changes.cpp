class Solution {
public:
    int maxDistance(string s, int k) {
        int north=0,south=0,east=0,west=0;
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N') north++;
            else if(s[i]=='W') west++;
            else if(s[i]=='S') south++;
            else{
                east++;
            }
            int curr_md=abs(east-west)+abs(north-south);
            int steps=i+1;
            int wasted=steps-curr_md;
            int extra=0;
            if(wasted!=0){
                extra=min(2*k,wasted);
            }
            int final_md=extra+curr_md;
            res=max(res,final_md);
                    }
                    return res;
    }

};