class Solution {
public:
    int compareVersion(string version1, string version2) {
       int cnt1=0,cnt2=0;
       for(int i=0;i<version1.size();i++){
        if(version1[i]=='.') cnt1++;
       }
       for(int i=0;i<version2.size();i++){
        if(version2[i]=='.') cnt2++;
       }
       int size=max(cnt1+1,cnt2+1);
       vector<int> v1(size,0);
       vector<int> v2(size,0);
       //filling of v1 & v2
       string temp="";
       int pointer=0;
       for(int i=0;i<version1.size();i++){
        if(version1[i]=='.'){
            int num=stoi(temp);
            v1[pointer]=num;
            pointer++;
            temp="";
            continue;
        }
        temp+=version1[i];
       }
       v1[pointer]=stoi(temp);
       temp="";
       pointer=0;
         for(int i=0;i<version2.size();i++){
        if(version2[i]=='.'){
            int num=stoi(temp);
            v2[pointer]=num;
            pointer++;
            temp="";
            continue;
        }
        temp+=version2[i];
       }
       v2[pointer]=stoi(temp);
         //comparison
         for(int i=0;i<size;i++){
            if(v1[i]<v2[i]){
                return -1;
            }
            else if(v1[i]>v2[i]) {return 1;}
         }
         return 0;
    }
};