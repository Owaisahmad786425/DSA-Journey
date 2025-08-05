class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[j] && baskets[j]>=fruits[i]){
                    vis[j]=1;
                    break;
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                res++;
            }
        }
        return res;
    }
};