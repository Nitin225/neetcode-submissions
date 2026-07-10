class Solution {
private:
    int manDist(vector<vector<int>> &points, int p1, int p2){
        return abs(points[p1][0] - points[p2][0]) +
                abs(points[p1][1] - points[p2][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, 
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        vector<bool> vis(n, false);
        int cost = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto p = pq.top();
            int wt = p.first;
            int node = p.second;
            pq.pop();

            if(vis[node]) continue;

            vis[node] = true;
            cost += wt;

            for(int i=0; i<n; i++){
                if(!vis[i]){
                    int dist = manDist(points, node, i);
                    pq.push({dist, i});
                }
            }
        }
        return cost;

    }
};
