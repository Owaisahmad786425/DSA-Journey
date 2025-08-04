class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         int var1=fruits[0];
        int r=1;
        int l=0;
        int n=fruits.size();
        if(n==1){
            return 1;
        }
        int max_len=0;
        int var2=-1;
        while(r<n){
            if(fruits[r]!=var1 && var2==-1){
                var2=fruits[r];
                    int len=r-l+1;
                max_len=max(max_len,len);
                r++;
                continue;
            }
            else if(fruits[r]!=var1 && fruits[r]!=var2){
                int temp=fruits[l];
                while(temp==fruits[l]){
                    l++;
                }
                var1=fruits[l];
                var2=-1;
        r=l+1;
                continue;
            }
            else if(var1==fruits[r] || fruits[r]==var2){
                if(fruits[r]==var1){
              
                     int len=r-l+1;
                    max_len=max(max_len,len);
                    r++;
                }
                else if(fruits[r]==var2){
                   int len=r-l+1;
                    max_len=max(max_len,len);
            r++;
                }
            }
        }
        return max_len;
    }
};