class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n+1);
        for(auto d : edges){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        queue<pair<int,int>> q;
        vector<int> vis(n+1, 0);
     
        q.push({0,-1});
        vis[0] = 1;
    
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjNode: graph[node]){
                if(!vis[adjNode]){
                    q.push({adjNode, node});
                    vis[adjNode] = 1;
                }
                else{
                    if(parent != adjNode)
                        return false;
                }
            }
        }
            
        
        for(int i=0; i<n; i++)
            if(!vis[i]) return false;  

        return true;
    }
};
