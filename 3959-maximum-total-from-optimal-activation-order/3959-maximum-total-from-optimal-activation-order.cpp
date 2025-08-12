class Solution {
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        if(p1.first==p2.first){
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        vector<pair<int,int>> maps;
        int n=limit.size();
        vector<int> freq(n+1,0);
        vector<bool> vis(n+1,0);
        for(int i=0;i<n;i++){
            freq[limit[i]]++;
        }
        for(int i=0;i<n;i++){
            int fst= limit[i];
            int scd=value[i];
            maps.push_back({fst,scd});
        }
        sort(maps.begin(),maps.end(),comp);
        int count=0;
        long long res=0;
        for(int i=0;i<n;i++){
            if(vis[maps[i].first]) continue;
            if(count>=maps[i].first){
                vis[count]=1;
                int st=count;
                count-=freq[count];
                  if(count<0) count=0;
                freq[st]=0;
            }
            else{
                count++;
                res+=maps[i].second;
                vis[count]=1;
                int st=count;
                count-=freq[count];
                 if(count<0) count=0;
                 freq[st]=0;
            }
        }
        return res;
    }
};