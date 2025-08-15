class Solution {
    typedef pair<double,pair<int,int>> P;
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<P,vector<P>,greater<P>> min_heap;
        int iterations=k;
        int curr_last=arr.size()-1;
        while(iterations>0){
           for(int i=0;i<curr_last;i++){
              double fraction=1.0*arr[i]/arr[curr_last];
              min_heap.push({fraction,{arr[i],arr[curr_last]}});
           }
           iterations--;
           curr_last--;
        }
        while(k>1){
            min_heap.pop();
            k--;
        }
        return {min_heap.top().second.first,min_heap.top().second.second};
    }
};