class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> store(n,1);
        //left to right traversal 
        for(int i=0;i<n-1;i++){
            if(ratings[i]<ratings[i+1] && store[i+1]<=store[i]){
                store[i+1]=store[i]+1;
            }
        }
        //right to left traversal
         for(int i=n-1;i>0;i--){
            if(ratings[i]<ratings[i-1] && store[i-1]<=store[i]){
                store[i-1]=store[i]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=store[i];
        }
        return ans;
    }
};