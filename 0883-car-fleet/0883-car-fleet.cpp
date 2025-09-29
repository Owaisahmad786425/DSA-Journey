class Solution {
    static bool comp(pair<int,int> &p1,pair<int,int> &p2){
        return p1.first<p2.first;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
           int n=position.size();
           stack<double> st;
           vector<pair<int,int>> store;
           for(int i=0;i<n;i++){
              store.push_back({position[i],speed[i]});
           }
           sort(store.begin(),store.end(),comp);

           for(int i=n-1;i>=0;i--){
            double steps=(double)(target-store[i].first)/(double)store[i].second;
            if(st.empty()){
                st.push(steps);
                continue;
            }
            else if(st.top()>=steps){
            }
            else{
                st.push(steps);
            }
           }
           return st.size();
    }
};