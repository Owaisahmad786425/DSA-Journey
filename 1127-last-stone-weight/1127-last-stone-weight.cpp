class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for(auto &it:stones){
            max_heap.push(it);
        }
        while(max_heap.size()>1){
            int first=max_heap.top();
            max_heap.pop();
            int second=max_heap.top();
            max_heap.pop();
            if(first!=second){
                first=first-second;
                max_heap.push(first);
            }
            
        }
        if(max_heap.size()==0) return 0;

        return max_heap.top();

    }
};