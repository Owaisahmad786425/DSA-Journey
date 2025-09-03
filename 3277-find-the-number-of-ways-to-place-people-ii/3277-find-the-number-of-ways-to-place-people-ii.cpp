class Solution {
    static bool comp(vector<int> vec1,vector<int> vec2){
         if(vec1[0]==vec2[0]){
            return vec1[1]>vec2[1];
         }

         return vec1[0]<vec2[0];
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int res=0;
        for(int i=0;i<points.size();i++){
            int x1=points[i][0];
            int y1=points[i][1];
            long long max_y=-1e9-1;
            for(int j=i+1;j<points.size();j++){
                int x2=points[j][0];
                int y2=points[j][1];
                if(x2>=x1 && y2<=y1 && y2>max_y){
                     res++;
                     max_y=y2;
                }
            }
        }
        return res;
    }
};