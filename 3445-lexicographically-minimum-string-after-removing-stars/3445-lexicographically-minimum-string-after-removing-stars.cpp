class Solution {
    static bool comp(pair<char,int> p1,pair<char,int> p2){
        if(p1.first==p2.first) return p1.second<p2.second;

        return p1.first>p2.first;
    }
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(&comp)> min_heap(comp);
        vector<bool> vis(s.size());
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                vis[min_heap.top().second]=1;
                min_heap.pop();
                continue;
            }
            min_heap.push({s[i],i});
        }
        string res="";
        for(int i=0;i<s.size();i++){
            if(!vis[i] && s[i]!='*') res+=s[i];
        }
        return res;
    }
};