class Solution {
    bool check(int val){
        while(val>0){
            if(val%10==0) return false;
            val/=10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=1;
        int b=n-1;
        while(a<=b){
            if(check(a) && check(b)) return {a,b};

            a++;
            b--;
        }
        return {};
      
    }
};