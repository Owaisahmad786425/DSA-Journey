class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
       int row1=0,col1=0,row2=n-1,col2=m-1;
       while(row1<=row2 && col1<=col2){
        int mid1=(row1+row2)/2;
        int mid2=(col1+col2)/2;
        if(matrix[mid1][mid2]==target) return true;

        else if(matrix[mid1][mid2]>target){
            if(mid2>0){
                col2=mid2-1;
            }
            else{
                row2=mid1-1;
                col2=m-1;
            }
        }
        else{
            if(mid2<m-1){
                col1=mid2+1;
            }
            else{
                row1=mid1+1;
                col1=0;
            }
        }
       }
       return false;
    }
};