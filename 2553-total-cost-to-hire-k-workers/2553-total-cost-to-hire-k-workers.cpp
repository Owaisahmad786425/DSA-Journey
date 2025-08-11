class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
     //thoda lamba hai code but koi nhi
     priority_queue<int,vector<int>,greater<int>> left_min_heap,right_min_heap;
     for(int i=0;i<candidates;i++){
        left_min_heap.push(costs[i]);
     }
     int n=costs.size();
     int l=candidates-1;
     int h=n-1;
     while(l<h && h>=n-candidates){
        right_min_heap.push(costs[h]);
        h--;
     }
     h+=1;
     long long res=0;
     while(k>0 && l<h && !left_min_heap.empty() && !right_min_heap.empty()){
        if(left_min_heap.top()<=right_min_heap.top()){
            res+=left_min_heap.top();
            left_min_heap.pop();
            l++;
            if(l<h){
                left_min_heap.push(costs[l]);
            }
        }
        else{
               res+=right_min_heap.top();
            right_min_heap.pop();
            h--;
            if(l<h){
                right_min_heap.push(costs[h]);
            }
        }
        k--;
     }
    
    while(k>0 && !left_min_heap.empty() && !right_min_heap.empty()){
           if(left_min_heap.top()<=right_min_heap.top()){
            res+=left_min_heap.top();
            left_min_heap.pop();
        }
        else{
               res+=right_min_heap.top();
            right_min_heap.pop();
        }
        k--;
    }
  while(k > 0 && left_min_heap.empty() && !right_min_heap.empty()) {
    res += right_min_heap.top();
    right_min_heap.pop();
    k--;
}
while(k > 0 && right_min_heap.empty() && !left_min_heap.empty()) {
    res += left_min_heap.top();
    left_min_heap.pop();
    k--;
}

return res;
    }
};