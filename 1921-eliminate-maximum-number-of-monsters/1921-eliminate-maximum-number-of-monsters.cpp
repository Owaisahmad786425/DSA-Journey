class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=speed.size();
        vector<float> time;
        for(int i=0;i<n;i++){
            float var=((float)dist[i]/(float)speed[i]);
            time.push_back(var);
        }
        sort(begin(time),end(time));
        int res=0;
        int time_store=0;
        for(int i=0;i<n;i++){
            time[i]-=time_store;
            if(time[i]<=0) break;
            res++;
            time_store++;
        }
        return res;
    }
};