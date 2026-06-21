class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it])
                dfs(it, graph, vis, st);
        }
        
        st.push(node);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto d : edges){
            graph[d[1]].push_back(d[0]);
        }
        
        vector<int> indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it : graph[i]){
                indegree[it]++;
            }
        }
    
        queue<int> q;
        for(int i=0; i<n; i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : graph[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(ans.size() != n) return {};
        return ans;
        

    }
};