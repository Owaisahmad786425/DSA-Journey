class Solution {
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        if(p1.first==p2.second){
            return p1.second>p2.second;
        }
        return p1.first<p2.second;
    }
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
        while(i<n){
            if(w>=mapping[i].first){
                max_heap.push({mapping[i].second,mapping[i].first});
                i++;
              continue;
            }
            while(k>0 && !max_heap.empty() && w<mapping[i].first){
                w+=max_heap.top().first;
                max_heap.pop();
                k--;
            }
            if(w<mapping[i].first) break;
        }
      
         while(k>0 && !max_heap.empty()){
            w+=max_heap.top().first;
                max_heap.pop();
                k--;
         }
return w;
    }
};