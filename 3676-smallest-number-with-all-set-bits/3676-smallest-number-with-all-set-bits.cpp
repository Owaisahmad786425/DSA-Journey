class Solution {
public:
    int smallestNumber(int n) {
        int power=1;
        int num=0;
        while(num<n){
            num=pow(2,power)-1;
            power++;
        }

        return num;
    }
};