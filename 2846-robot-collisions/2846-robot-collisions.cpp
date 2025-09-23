class Solution {
    static bool comp(vector<int> &v1,vector<int> &v2){
        return v1[0]<v2[0];
    }
     static bool comp2(pair<int,int> &p1,pair<int,int> &p2){
        return p1.second<p2.second;
    }
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
         int n=positions.size();
         vector<vector<int>> merge(n,vector<int>(4));
         for(int i=0;i<n;i++){
            merge[i][0]=positions[i];
            merge[i][1]=healths[i];
            if(directions[i]=='L') merge[i][2]=0;
            else{
                merge[i][2]=1;
            }
            merge[i][3]=i;
         }
         sort(merge.begin(),merge.end(),comp);
         vector<pair<int,int>> store;
         stack<pair<int,int>> st;
         for(int i=0;i<n;i++){
            if(merge[i][2]==1){
                st.push({merge[i][1],merge[i][3]});
                continue;
            }

            while(!st.empty()&& st.top().first<merge[i][1]){
                merge[i][1]--;
                st.pop();
            }
            if(!st.empty() && st.top().first==merge[i][1]){
                st.pop();
                continue;
            }
            else if(!st.empty() && st.top().first>merge[i][1]){
                st.top().first--;
                if(st.top().first==0) st.pop();
                continue;
            }
            else if(st.empty()){
               store.push_back({merge[i][1],merge[i][3]});
               continue;
            }
         }
         while(!st.empty()){
            store.push_back(st.top());
            st.pop();
         }
         sort(store.begin(),store.end(),comp2);
         vector<int> res;
         for(int i=0;i<store.size();i++){
            res.push_back(store[i].first);
         }

         return res;
         
    }
};