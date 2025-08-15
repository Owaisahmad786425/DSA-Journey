class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
      priority_queue<pair<double,pair<int,int>>> max_heap;
      int n=arr.size();
      for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double fraction=1.0*arr[i]/arr[j];
            max_heap.push({fraction,{arr[i],arr[j]}});
            if(max_heap.size()>k) max_heap.pop();
            }
      }
      return {max_heap.top().second.first,max_heap.top().second.second};  
    }
};