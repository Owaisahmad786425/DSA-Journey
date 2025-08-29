class Solution {
public:
    long long flowerGame(int n, int m) {
       int odd1=0;
       int even1=0;
       int odd2=0;
       int even2=0;
       for(int i=1;i<=n;i++){
        if(i%2==0) even1++;
        else{
            odd1++;
        }
       } 
       for(int i=1;i<=m;i++){
           if(i%2==0) even2++;
        else{
            odd2++;
        }
       }
       long long res=(1LL*even2*odd1)+(1LL*even1*odd2);
       return res;
    }
};