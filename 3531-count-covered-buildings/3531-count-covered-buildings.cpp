class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int,int>> row(n+1,{1e9,-1e9});
        vector<pair<int,int>> col(n+1,{1e9,-1e9});
        //populate this owais
        //row populate kr owais
        for(auto it:buildings){
            row[it[0]].first=min(row[it[0]].first,it[1]);
            row[it[0]].second=max(row[it[0]].second,it[1]);
        }
        //col populate kar owais
         for(auto it:buildings){
            col[it[1]].first=min(col[it[1]].first,it[0]);
            col[it[1]].second=max(col[it[1]].second,it[0]);
        }
       
       //main logic laga owais
       int res=0;
       for(auto it:buildings){
        int val1=it[0];
        int val2=it[1];
        int check1=row[val1].first;
        int check2=row[val1].second;
        int check3=col[val2].first;
        int check4=col[val2].second;

        if(val1>check3 && val1 <check4 && val2>check1 && val2<check2) res++;

       }
return res;
    }
};