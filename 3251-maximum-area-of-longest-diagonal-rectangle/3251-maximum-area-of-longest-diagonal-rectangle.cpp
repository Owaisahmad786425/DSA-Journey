class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int dig_len=0;
        int res=0;
        int n=dimensions.size();
        for(int i=0;i<n;i++){
          int len=dimensions[i][0];
          int width=dimensions[i][1];
          int val=(len*len)+(width*width);
        int area=len*width;
          if(val>dig_len){
             dig_len=val;
            res=area;
          }
          else if(dig_len==val) res=max(res,(len*width));
        }
        return res;
    }
};