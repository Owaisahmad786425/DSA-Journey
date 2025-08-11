class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>> res;
        priority_queue<pair<int,vector<int>>> max_heap;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                long long sum=nums1[i]+nums2[j];
                if(max_heap.size()<k){
                    max_heap.push({sum,{nums1[i],nums2[j]}});
                }
                else if(sum<max_heap.top().first){
                    max_heap.pop();
                    max_heap.push({sum,{nums1[i],nums2[j]}});
                }
                else{
                    break;
                }
            }
        }
        while(!max_heap.empty()){
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return res;
        
    }
};