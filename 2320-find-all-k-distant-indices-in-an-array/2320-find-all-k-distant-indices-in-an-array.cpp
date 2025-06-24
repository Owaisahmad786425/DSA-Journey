class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        //brute force bhut simple hai
        vector<int> list;
        set<int> st;
        int n=nums.size();
        vector<int> indices;
        for(int i=0;i<n;i++){
          if(nums[i]==key){
            indices.push_back(i);
          }
        }
        for(int i=0;i<indices.size();i++){
            int index=indices[i];
            for(int j=0;j<n;j++){
                if(abs(index-j)<=k){
                    st.insert(j);
                }
            }
        }
        for(auto it:st){
            list.push_back(it);
        }
        sort(list.begin(),list.end());
        return list;
    }
};