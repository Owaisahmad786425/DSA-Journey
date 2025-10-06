class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        if(p==0 || (p==1 && n==1)) return 0;
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums[n-1];
        int res;
        while(l<=r){
            int mid=(l+r)/2;
            priority_queue<int> max_heap;
            int i=n-1;
            while(i>0){
               if(abs(nums[i]-nums[i-1])<=mid) {
                max_heap.push(abs(nums[i]-nums[i-1]));
                i-=2;
               }
               else i--;
            }

            if(max_heap.size()>=p && max_heap.top()==mid){
                res=mid;
                r=mid-1;
            }
            else if(max_heap.size()>=p && max_heap.top()!=mid) r=mid-1;
            else l=mid+1;
        }
        return res;
    }
};