class Solution {
public:

    bool dfsCheck(int node, vector<vector<int>> &adj , vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
    
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis) == true)
                    return true;
            }
            else if(pathVis[it])
                return true;
        }
    
        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num) ;
        for(auto x : pre){
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(num, 0);      
        vector<int> pathVis(num, 0);
    
        for(int i=0; i<num; i++){
            if(!vis[i]){
                if(dfsCheck(i, adj, vis, pathVis) == true)
                    return false;
            }
        }
        return true;


    }
};
