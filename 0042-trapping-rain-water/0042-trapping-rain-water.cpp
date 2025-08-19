class Solution {
    typedef pair<int,int> P;
public:
    int trap(vector<int>& height) {
         stack<P> st;
         int res=0;
         int n=height.size();
         for(int i=0;i<n;i++){
            if(!st.empty() && st.top().first==height[i]) st.top().second++;
            while(!st.empty() && st.top().first<height[i]){
               P store=st.top();
               st.pop();
               if(st.empty()) break;
               int mini=min(st.top().first,height[i]);
               res+=(abs(mini-store.first)*store.second);
               store.first=mini;
               if(store.first==st.top().first && store.first==height[i]){
                st.top().second+=store.second+1;
                break;
               }
               if(store.first==st.top().first)st.top().second+=store.second;

               else if(store.first==height[i]){
                store.second+=1;
                st.push(store);
               }
            }
           
            if(st.empty() || st.top().first!=height[i]){
                st.push({height[i],1});
            }
         }
         return res;
    }
};