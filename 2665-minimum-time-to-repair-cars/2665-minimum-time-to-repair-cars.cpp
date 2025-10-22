class Solution {
    bool check(vector<int> &ranks,int cars,long long time,int n){
        long long total_repaired_cars=0;
        for(int i=0;i<n;i++){
            if(ranks[i]==0) continue;
            total_repaired_cars+=sqrt(time/ranks[i]);;
        }
        return total_repaired_cars>=cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int maxEl=*max_element(begin(ranks),end(ranks));
        long long l=1;
        long long r=(1LL*maxEl*cars*cars);
        int n=ranks.size();
        long long res=-1;
        while(l<=r){
            long long time=(l+r)/2;

            if(check(ranks,cars,time,n)){
                res=time;
                r=time-1;
            }
            else l=time+1;
        }

        return res;
    }
};