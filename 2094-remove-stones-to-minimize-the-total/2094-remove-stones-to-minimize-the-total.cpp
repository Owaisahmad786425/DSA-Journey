class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> max_heap;
        int n=piles.size();
        for(int i=0;i<n;i++){
            max_heap.push(piles[i]);
        }
        while(k>0){
            //O(1) operation
            int var=max_heap.top();
            int to_remove=floor(var/2);
            max_heap.pop();
            var=(var-to_remove);
            max_heap.push(var);
            k--;
        }
        int res=0;
      while(!max_heap.empty()){
        res+=max_heap.top();
        max_heap.pop();
      }
        return res;

    }
};