class Solution {
    bool check(char a){
        if(a=='a'|| a=='e'|| a=='i'|| a=='o'|| a=='u'){
            return true;
        }
        return false;
    }
public:
    long long beautifulSubstrings(string s, int k) {
        unordered_map<long long,unordered_map<long long,long long>> mp;
        long long vowels=0;
        long long consonents=0;
        mp[0][0]=1;
        int n=s.size();
        long long res=0;
        for(int i=0;i<n;i++){
            if(check(s[i])){
                vowels++;
            }
            else{
                consonents++;
            }
            long long diff=vowels-consonents;
       
                for(auto it:mp[diff]){
                    if((vowels%k-it.first)*(vowels%k-it.first)%k==0){
                        res+=it.second;
                    }
                }
            
            mp[diff][vowels%k]++;
        }
        return res;
    }
};