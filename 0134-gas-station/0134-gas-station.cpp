class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int i=-1;
        int j=n;
        int total=0;
        while(i<j){
           if(total>=0){
            i++;
            if(i>=n) break;
            total+=gas[i];
            total-=cost[i];
           }
           else{
            j--;
             total+=gas[j];
            total-=cost[j];
           }
        }
        if(total<0) return -1;
        if(j==n) return 0;

        return j;
    }
};