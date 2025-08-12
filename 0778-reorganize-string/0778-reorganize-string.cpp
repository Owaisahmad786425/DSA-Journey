class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(auto &it:s){
            freq[it-'a']++;
        }
        priority_queue<pair<int,char>> max_heap;
        //push in the heap with the frequency
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                max_heap.push({freq[i],i+'a'});
            }
        }
       string res;
       while(!max_heap.empty()){
        pair<int,char> first_add=max_heap.top();
        max_heap.pop();
        if(!max_heap.empty()){
            pair<int,char> second_add=max_heap.top();
            max_heap.pop();
            res.push_back(first_add.second);
            res.push_back(second_add.second);
            first_add.first=first_add.first-1;
            second_add.first=second_add.first-1;
            if(first_add.first>0){
                max_heap.push({first_add.first,first_add.second});
            }
            if(second_add.first>0){
                max_heap.push({second_add.first,second_add.second});
            }
        }
        else{
           res.push_back(first_add.second);
           first_add.first=first_add.first-1;
           if(first_add.first>0){
            max_heap.push({first_add.first,first_add.second});
            break;
           }
        }
       }
      if(max_heap.size()>0) return "";
      return res;
  
    }
};