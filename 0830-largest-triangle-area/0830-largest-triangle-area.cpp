class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
       int n=points.size();
       double res=0.0;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                pair<int,int> a,b,c;
                a.first=points[i][0];
                a.second=points[i][1];
                b.first=points[j][0];
                b.second=points[j][1];
                c.first=points[k][0];
                c.second=points[k][1];
                double side1 = sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
double side2 = sqrt(pow(a.first-c.first,2) + pow(a.second-c.second,2));
double side3 = sqrt(pow(b.first-c.first,2) + pow(b.second-c.second,2));

                double s=(side1+side2+side3)/2;
                double store=(s*(s-side1)*(s-side2)*(s-side3));
                double area=sqrt(store);
                if(res<area) res=area;
            }
        }
       }
       return res;
    }
};