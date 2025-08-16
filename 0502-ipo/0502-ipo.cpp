class Solution {

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> mapping(n);
        priority_queue<pair<int,int>> max_heap;
        for(int i=0;i<n;i++){
            int first=capital[i];
            int second=profits[i];
            mapping[i]={first,second};
        }
        sort(mapping.begin(),mapping.end());
        int i=0;
        while(k>0){
            while(i<n && w>=mapping[i].first){
                max_heap.push({mapping[i].second,mapping[i].first});
                i++;
            }
            if(max_heap.empty()) break;

            w+=max_heap.top().first;
            k--;
            max_heap.pop();
        }
        
return w;
    }
};