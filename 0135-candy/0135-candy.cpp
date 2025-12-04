class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int res=n;
        int i=1;
        while(i<n){
       if(ratings[i]==ratings[i-1]){
        i++;
        continue;
       }
       int peak=0;
       //increasing slope chalayega owais
       while(ratings[i]>ratings[i-1]){
        peak++;
        res+=peak;
        i++;
        if(i==n) return res;
       }
int dip=0;
//decreasing slope hai owais
while(ratings[i]<ratings[i-1]){
    dip++;
    res+=dip;
    i++;
    if(i==n){
res-=min(peak,dip);
return res;
    }
}
  res-=min(peak,dip);
        }
        return res;
    }
};