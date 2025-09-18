class TaskManager {
public:
    set<pair<int,int>>st;
    unordered_map<int,int>ttou;
    unordered_map<int,int>ttop;
    TaskManager(vector<vector<int>>& tasks) {
       for(auto it:tasks){
        st.insert({it[2],it[1]});
        ttou[it[1]]=it[0];
        ttop[it[1]]=it[2];
       }
        
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority,taskId});
    ttop[taskId]=priority;
    ttou[taskId]=userId;
        
    }
    
    void edit(int taskId, int newPriority) {
        int p=ttop[taskId];
        st.erase({p,taskId});
        st.insert({newPriority,taskId});
        ttop[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        int p=ttop[taskId];
        ttop.erase(taskId);
        ttou.erase(taskId);
        st.erase({p,taskId});


    }
    
    int execTop() {
        if (st.empty()) return -1;
        auto it=*st.rbegin();
        int t=it.second;
        int p=it.first;
        int ans=ttou[t];
        ttop.erase(t);
        ttou.erase(t);
        st.erase({p,t});
        return ans;
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