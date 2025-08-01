class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
  for(int k=1;k<numRows;k++){

int i=-1;
int j=0;
vector<int> temp;
int n=res[k-1].size();
while(i<n){
    if(i==-1){
        temp.push_back(res[k-1][j]);
        i++;
        j++;

    }
    else if(j==n){
        temp.push_back(res[k-1][i]);
        i++;
        j++;
    }
    else {
        int sum=res[k-1][i]+res[k-1][j];
        temp.push_back(sum);
        i++;
        j++;
    }
}
res.push_back(temp);
  }
return res;

    }
};