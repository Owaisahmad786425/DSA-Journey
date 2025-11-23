class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();

        int total=0;
        vector<int> rem2;
        vector<int> rem1;
        for(auto it:nums){
            if(it%3==1) rem1.push_back(it);
            else if(it%3==2) rem2.push_back(it);

            total+=it;
        }
        sort(begin(rem1),end(rem1));
        sort(begin(rem2),end(rem2));
        int actual_rem=total%3;
        if(actual_rem==1){
            int mini=1e9;
            if(rem1.size()==0) mini=min(mini,(rem2[0]+rem2[1]));
             else if(rem2.size()<=1) mini=min(mini,rem1[0]);
       else mini=min(mini,min(rem1[0],(rem2[0]+rem2[1])));
            total-=mini;
        }

        else if(actual_rem==0) return total;
        else{
            int mini=1e9;
        if(rem2.size()==0) mini=min(mini,(rem1[0]+rem1[1]));
        else if(rem1.size()<=1) mini=min(mini,rem2[0]);
        else mini=min(mini,min(rem2[0],(rem1[0]+rem1[1])));
        total-=mini;
        }

        return total;
    }
};