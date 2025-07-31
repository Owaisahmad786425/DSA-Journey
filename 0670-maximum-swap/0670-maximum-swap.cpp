class Solution {
    bool static comp(pair<char,int> p1,pair<char,int> p2){
        return p1.first>p2.first;
    }
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<pair<char,int>> vec(s.size());
        int i=0;
        for(auto &it:s){
            vec.push_back({it,i});
            i++;
        }
        sort(vec.begin(),vec.end(),comp);
        int pointer=0;
        int j=0;
        while(pointer<n){
            if(s[pointer]!=vec[j].first && vec[j].first!=vec[j+1].first){
              swap(s[pointer],s[vec[j].second]);
              break;
            }
            else if(s[pointer]!=vec[j].first && vec[j].first==vec[j+1].first){
                j++;
            }
            else{
            pointer++;
            j++;
            }
        }
return stoi(s);
    }
};