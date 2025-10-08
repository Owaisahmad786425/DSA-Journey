class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int n=nums1.size();
        int m=nums2.size();
        int left_elements=(m+n+1)/2;
        int l=0;
        int r=n;
        while(l<=r){
            int mid=(l+r)/2;
            int x1=mid-1;
            int x2=mid;
            int x3=(left_elements-mid)-1;;
            int x4=x3+1;
            if(x1==-1) x1=-1e9;
            else x1=nums1[x1];
            if(x2==n) x2=1e9;
            else x2=nums1[x2];
            if(x3==-1) x3=-1e9;
            else x3=nums2[x3];
            if(x4==m) x4=1e9;
            else x4=nums2[x4];
            //conditions for shifting
            if(x1<=x4 && x3<=x2){
                if((m+n)%2!=0) return max(x1,x3);

                else{
                    return (max(x1,x3)+min(x2,x4))/2.0;
                }

            }
            else if(x1<=x4 && x3>x2) l=mid+1;
            else r=mid-1;
        }
        return 0;
    }
};