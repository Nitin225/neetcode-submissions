class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto x : edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        queue<int> q;
        vector<int> vis(n, 0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto adj : graph[node]){
                        if(!vis[adj]){
                            q.push(adj);
                            vis[adj] = 1;
                        }
                    }
                }
            }
        }
        return count;
    }
};
