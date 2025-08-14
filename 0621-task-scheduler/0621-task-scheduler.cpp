class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto &it:tasks){
            freq[it-'A']++;
        }
        sort(begin(freq),end(freq));
        int maxi=freq[25];
        int gaps=freq[25]-1;
        int idle_spot=gaps*n;
        for(int i=24;i>=0;i--){
            idle_spot-=min(freq[i],gaps);
        }
        if(idle_spot>0){
            return idle_spot+tasks.size();
        }

        return tasks.size();
    }
};