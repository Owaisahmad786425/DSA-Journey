class TaskManager {
    unordered_map<int,pair<int,int>> mp;
    priority_queue<pair<int,pair<int,int>>> pq;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks){
            int tid=it[1];
            int uid=it[0];
            int prio=it[2];
            mp[tid]={uid,prio};
            pq.push({prio,{tid,uid}});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={userId,priority};
        pq.push({priority,{taskId,userId}});
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].second=newPriority;
        pq.push({newPriority,{taskId,mp[taskId].first}});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty() && (mp.find(pq.top().second.first)==mp.end() || mp[pq.top().second.first].second!=pq.top().first)){
            pq.pop();
        }
        if(pq.empty()) return -1;

        int tid=pq.top().second.first;
        int uid=pq.top().second.second;
        int prio=pq.top().first;
        mp.erase(tid);
        pq.pop();
        return uid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */