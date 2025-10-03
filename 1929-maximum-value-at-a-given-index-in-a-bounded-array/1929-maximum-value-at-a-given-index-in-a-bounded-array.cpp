class Solution {
    bool fun(int mid,int index,int maxSum,int n){
        long long val=mid-1;
        long long size1=index-0;
        long long size2=(n-1)-index;
        long long sum=0;
        if(val<0){
            if(mid<=maxSum) return true;
            return false;
        }
        else{
            if(size1>=val){
                int rem=size1-val;
                sum+=((1LL*val*(val+1))/2);
                sum+=(1*rem);
            }
            else if(size1<val){
                int store=val-size1;
                sum+=(((1LL*val*(val+1))/2)-((1LL*store*(store+1))/2));
            }

             if(size2>=val){
                 int rem=size2-val;
                sum+=((1LL* val*(val+1))/2);
                sum+=(1*rem);
            }
            else if(size2<val){
                int store=val-size2;
                sum+=(((1LL*val*(val+1))/2)-((1LL*store*(store+1))/2));
            }
        }
        sum+=mid;
        return sum<=maxSum;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int l=0;
        int r=maxSum;
        int res=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(fun(mid,index,maxSum,n)){
                res=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};