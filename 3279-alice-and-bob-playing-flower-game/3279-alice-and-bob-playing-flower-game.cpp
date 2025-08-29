class Solution {
public:
    long long flowerGame(int n, int m) {
    
     long long a=1LL*((n+1)/2)*(m/2);
     long long b=1LL*((m+1)/2)*(n/2);
     return a+b;



    }
};