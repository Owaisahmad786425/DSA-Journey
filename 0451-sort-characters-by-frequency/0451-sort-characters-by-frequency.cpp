class Solution {
public:
    string frequencySort(string s) {
        vector<int> lower_case_freq(26,0);
        vector<int> upper_case_freq(26,0);
        vector<int> digit(10,0);
        priority_queue<pair<int,char>> max_heap;
        for(int i=0;i<s.size();i++){
            if(s[i]>=65 && s[i]<=90){
                upper_case_freq[s[i]-'A']++;
                continue;
            }
            else if(s[i]>=97 && s[i]<=122)
            lower_case_freq[s[i]-'a']++;
            else {
                digit[s[i]-'0']++;
            }
        }
        for(int i=0;i<26;i++){
            if(lower_case_freq[i]!=0){
                max_heap.push({lower_case_freq[i],i+'a'});
            }
            if(upper_case_freq[i]!=0){
                 max_heap.push({upper_case_freq[i],i+'A'});
            }
            if(i<=9 && digit[i]!=0){
                max_heap.push({digit[i],i+'0'});
            }
        }
        string res="";
        while(!max_heap.empty()){
            int freq=max_heap.top().first;
  
            char character=max_heap.top().second;
                      max_heap.pop();
            for(int i=0;i<freq;i++){
                res+=character;
            }
        }
        return res;
    }
};