class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        for(int i=0;i<n;i++){
            if(i+k<n){
                energy[i+k]=max(energy[i+k],energy[i]+energy[i+k]);
            }
        }
        int res=INT_MIN;
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            int j=i;
            while(j+k<n){
                visited[j]=1;
                j=j+k;
            }
            res=max(res,energy[j]);
        }
           return res;
    }
};