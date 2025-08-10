class Solution {
    bool static comp(pair<int,int> p1,pair<int,int> p2){
        return p1.second>p2.second;
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vec;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums1[i],nums2[i]});
        }
        sort(vec.begin(),vec.end(),comp);
        priority_queue<int,vector<int>,greater<int>> min_heap;
        long long sum=0;
        long long res=0;
        for(int i=0;i<k;i++){
            sum+=vec[i].first;
            min_heap.push(vec[i].first);
        }
        res=max(res,(1LL*sum*vec[k-1].second));

        for(int i=k;i<n;i++){
        sum-=min_heap.top();
        min_heap.pop();
        sum+=vec[i].first;
        min_heap.push(vec[i].first);
        res=max(res,(1LL*sum*vec[i].second));
        }
        return res;

    }
};