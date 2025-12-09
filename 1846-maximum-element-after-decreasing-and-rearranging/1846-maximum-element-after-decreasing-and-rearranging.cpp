class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(i==0){
                arr[i]=1;
                continue;
            }
            else if(abs(arr[i]-arr[i-1])>1) arr[i]=arr[i-1]+1;
        }
        return arr[n-1];
    }
};