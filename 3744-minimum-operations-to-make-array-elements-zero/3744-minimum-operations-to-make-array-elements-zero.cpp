class Solution {
    long long fun(long long high){
        if(high<=3){
            return high;
        }
        long long op=3;
        long long var=4;
        int power=2;
        while(true){
            long long pov=pow(4,power);
            if(high>=pov){
                pov-=1;
                long long no_of_elements=(pov-var+1);
                op+=(no_of_elements*power);
                var=pov+1;
            }
            else if(high<pov){
                long long no_of_elements=(high-var+1);
                op+=(no_of_elements*power);
                break;
            }
            power++;
        }
        return op;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
       int n=queries.size();
       long long res=0;
       for(int i=0;i<n;i++){
        int l=queries[i][0];
        int r=queries[i][1];
        long long op1=fun(r);
        long long op2=fun(l-1);
        long long store=op1-op2;
        if(store%2!=0){
            res+=((store/2)+1);
        }
        else{
            res+=(store/2);
        }
       }
       return res;
    }
};