class Solution {
public:
    int maximumLength(string s) {
        map<pair<char,int>,int> mp;
        int n=s.size();
        string store="";
        int res=-1;
        int l=0;
        int r=0;
        while(r<n){
            while(s[l]!=s[r]){
                int size=store.size()-2;
                if(size>0 && res<size) res=size;
                store.pop_back();
                if(store.size()!=0){
                mp[{s[l],store.size()}]++;
                }
                 l++;
            }
            store+=s[r];
            mp[{s[r],store.size()}]++;
            r++;
        }
        int size=store.size()-2;
        if(size>0 && res<size){
            res=size;
        }
        for(auto it:mp){
            if(it.second>=3 && res<(int)it.first.second){
                res=(int)it.first.second;
            }
        }
        return res;
    }
};