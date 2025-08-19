class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
     priority_queue<int, vector<int>, greater<int>> hash;
        for(int i=0;i<n;i++){
            if(nums[i]<k){
                hash.push(nums[i]);
            }
        }

     if(hash.size()==0){
        return 0;
     }
     if(hash.size()==1){
        return 1;
     }
int res=0;
while(!hash.empty()){
    int first=hash.top();
hash.pop();
if(hash.size()==0){
    res++;
    break;
}
int second=hash.top();
hash.pop();
long long int temp = (long long)(min(first, second) * 2) + max(first, second);
res++;
if(temp<k){
hash.push(temp);
}
}
return res;

    }
};