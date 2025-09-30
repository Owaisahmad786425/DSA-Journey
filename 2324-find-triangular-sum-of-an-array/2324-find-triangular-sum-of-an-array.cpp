class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> store=nums;
        while(store.size()>1){
            vector<int> temp;
            for(int i=0;i<store.size()-1;i++){
                temp.push_back((store[i]+store[i+1])%10);
            }
          store=temp;
        }
        return store[0];
    }
};