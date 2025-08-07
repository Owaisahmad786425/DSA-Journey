class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> first_min_heap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> second_min_heap;
        for(int it=0;it<tasks.size();it++){
            int arrival_time=tasks[it][0];
            int processing_time=tasks[it][1];
            first_min_heap.push({arrival_time,{processing_time,it}});
        }
       long long int time=0;
        while(!first_min_heap.empty()){
            if(time<first_min_heap.top().first && second_min_heap.empty()){
                time+=(first_min_heap.top().first-time);
            }
            while(!first_min_heap.empty() && time >= first_min_heap.top().first){
             int pt=first_min_heap.top().second.first;
             int indices=first_min_heap.top().second.second;
                second_min_heap.push({pt,indices});
             
                first_min_heap.pop();
            }
            if(first_min_heap.empty()){
                while(!second_min_heap.empty()){
                     time+=second_min_heap.top().first;
                    ans.push_back(second_min_heap.top().second);
                     second_min_heap.pop();
                }
            }
            else{
            time+=second_min_heap.top().first;
            ans.push_back(second_min_heap.top().second);
            second_min_heap.pop();
            }
            
        }
return ans;
    }
};