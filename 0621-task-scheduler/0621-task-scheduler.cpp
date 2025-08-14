class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> max_heap;
        
        vector<int> freq(26,0);
        for(auto &it:tasks){
            freq[it-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0) max_heap.push({freq[i],i+'A'});
        }
       int res=0;
        while(!max_heap.empty()){
            pair<int,char> curr=max_heap.top();
            res++;
            max_heap.pop();
            int temp=0;
            stack<pair<int,char>> temp_storage;
            while(!max_heap.empty() && temp<n){
                pair<int,char> temp1=max_heap.top();
                max_heap.pop();
                temp1.first=temp1.first-1;
                if(temp1.first>0) temp_storage.push(temp1);
                 res++;
                temp++;
            }
            curr.first=curr.first-1;
            if(curr.first>0) max_heap.push(curr);
            if(max_heap.empty() && temp_storage.empty()) break;
            //idle state
            res+=n-temp;
            while(!temp_storage.empty()){
                max_heap.push(temp_storage.top());
                temp_storage.pop();
            }
           
        }
        return res;
    }
};