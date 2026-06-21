class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, stack<int>& st, bool& cycle){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it])
                dfs(it, graph, vis, pathVis, st, cycle);

            else if(pathVis[it])
                cycle = true;
        }
        
        pathVis[node] = 0;
        st.push(node);
    }

    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> graph(num);
        for(auto d : pre){
            graph[d[1]].push_back(d[0]);
        }

        vector<int> vis(num, 0);
        vector<int> pathVis(num, 0);
        
        stack<int> st;

        bool cycle = false;
        for(int i=0; i<num; i++)
            if(!vis[i])
                dfs(i, graph, vis, pathVis, st, cycle);

        if(cycle) return {}; 


        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};