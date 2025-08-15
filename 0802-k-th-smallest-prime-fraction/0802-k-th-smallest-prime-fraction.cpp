class Solution {
    typedef pair<double,pair<int,int>> P;
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<P,vector<P>,greater<P>> min_heap;
        for(int i=0;i<n-1;i++){
            double fraction=1.0*arr[i]/arr[n-1];
            min_heap.push({fraction,{i,n-1}});
        }

        while(k>1){
           P temp=min_heap.top();
           min_heap.pop();
           if(temp.second.second-1>temp.second.first){
           double fraction=1.0*arr[temp.second.first]/arr[temp.second.second-1];
           min_heap.push({fraction,{temp.second.first,temp.second.second-1}});
           }
                k--;
        }
   int i=min_heap.top().second.first;
   int j=min_heap.top().second.second;
   return  {arr[i],arr[j]};
    }
};