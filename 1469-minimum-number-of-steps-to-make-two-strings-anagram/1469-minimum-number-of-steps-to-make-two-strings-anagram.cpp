class Solution {
public:
    int minSteps(string s, string t) {
     vector<int> freq1(26,0);
     vector<int> freq2(26,0);
     //man nhi hai aaj DSA krne ka 
     int n=s.size();
     for(int i=0;i<n;i++){
        freq1[s[i]-'a']++;
        freq2[t[i]-'a']++;
     }   
     int res=0;
       for(int i=0;i<26;i++){
        if(freq1[i]>freq2[i]){
            res+=(freq1[i]-freq2[i]);
        }
       }
     return res;
    }
};