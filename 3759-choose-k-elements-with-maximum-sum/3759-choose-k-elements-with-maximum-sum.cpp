class Solution {
    typedef pair<int,int> P;
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<P> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums1[i],i});
        }
        vector<long long> ans(n,0);
        sort(arr.begin(),arr.end());
        priority_queue<int,vector<int>,greater<int>>heap;
        long long sum=0;
        for(int i=0;i<n;i++){
             if(heap.empty()){
                sum+=nums2[arr[i].second];
                heap.push(sum);
                continue;
             }
            if(i>0 && arr[i-1].first==arr[i].first){
                ans[arr[i].second]=ans[arr[i-1].second];
               if(heap.size()<=k){
                  sum+=nums2[arr[i].second];
                heap.push(nums2[arr[i].second]);
               }
               else{
                  sum-=heap.top();
                heap.pop();
                sum+=nums2[arr[i].second];
                heap.push(nums2[arr[i].second]);
               }
                continue;
            }
            if(heap.size()<=k){
                ans[arr[i].second]=sum;
                sum+=nums2[arr[i].second];
                heap.push(nums2[arr[i].second]);
            }
            else if(heap.size()>k){
                sum-=heap.top();
                heap.pop();
                ans[arr[i].second]=sum;
                sum+=nums2[arr[i].second];
                heap.push(nums2[arr[i].second]);
            }
        }
        return ans;
    }
};