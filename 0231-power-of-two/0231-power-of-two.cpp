class Solution {
public:
    bool isPowerOfTwo(int n) {

         int val=n;
        while(val>1 && val%2==0){
            val/=2;
        }
        return val==1;
    }
};