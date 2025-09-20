class Solution {
    vector<int> generate_lse(vector<int> temp){
        stack<int> st;
        vector<int> store(temp.size());
        for(int i=0;i<temp.size();i++){
            while(!st.empty() && temp[st.top()]>=temp[i]){
                st.pop();
            }
            if(st.empty()){
                store[i]=-1;
            }
            else{
                store[i]=st.top();
            }
            st.push(i);
        }
        return store;
    }

    vector<int> generate_rse(vector<int> temp){
        stack<int> st;
        vector<int> store(temp.size());
        for(int i=temp.size()-1;i>=0;i--){
            while(!st.empty() && temp[st.top()]>=temp[i]){
                st.pop();
            }
            if(st.empty()){
                store[i]=temp.size();
            }
            else{
                store[i]=st.top();
            }
            st.push(i);
        }
        return store;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> height(n,vector<int>(m,0));
        //populate the hieght array
         for(int i=0;i<m;i++){
            height[0][i]=(matrix[0][i]-'0');
         }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    height[i][j]=0;
                }
                else{
                    height[i][j]=height[i-1][j]+1;
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            vector<int> LSE=generate_lse(height[i]);
            vector<int> RSE=generate_rse(height[i]);
            for(int j=0;j<m;j++){
                int width = RSE[j] - LSE[j] - 1;
                res = max(res, width * height[i][j]);

            }
        }
      return res;
    }
};