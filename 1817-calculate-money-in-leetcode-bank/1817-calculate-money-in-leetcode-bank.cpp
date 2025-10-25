class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int val= 1;
        
        while (n > 0) {
            for (int day = 0; day < min(n, 7); day++) {
                res += val+ day;
            }
            
            n -= 7;
            val++;
        }
        
        return res;
    }
};