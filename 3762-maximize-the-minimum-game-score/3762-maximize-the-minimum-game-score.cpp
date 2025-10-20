class Solution {
    bool check(long long val,vector<int> &points,vector<long long> &gameScore,int n,int m){
        long long op=0;
        for(int i=0;i<n;i++){
            if(gameScore[i]>=val && i<n-1){
                op++;
                continue;
            }
            else if(gameScore[i]>=val &&i==n-1) break;
        long long store=abs(val-gameScore[i]);
   long long op2 = (store + points[i] - 1) / points[i];

op+=op2;
if(op>m) return false;

        if(i+1<n){
            gameScore[i+1]+=((op2-1)*points[i+1]);
        }
        op+=(op2-1);
        }
        return op<=m;
    }
public:
    long long maxScore(vector<int>& points, int m) {
        int n=points.size();
        long long low=1;
        long long high=1e15;
        long long res;
        if(m<n) return 0;
        while(low<=high){
            long long val=(low+high)/2;
             vector<long long> gameScore(n,0);
            if(check(val,points,gameScore,n,m)){
                res=val;
                low=val+1;
            }
            else high=val-1;
        }
        return res;
    }
};