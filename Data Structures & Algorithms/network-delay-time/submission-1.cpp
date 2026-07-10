class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto it : times){
            graph[it[0]].push_back({it[1], it[2]});
        }
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n+1, INT_MAX);

        dist[k] = 0;
        int mx = 0;
        pq.push({0,k});

        while(!pq.empty()){

            auto [dis,node]=pq.top();
            pq.pop();

            if(dis>dist[node])
                continue;

            for(auto [adj,wt]:graph[node]){

                if(dis+wt<dist[adj]){

                    dist[adj]=dis+wt;

                    pq.push({dist[adj],adj});
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            mx = max(mx, dist[i]);
        }

        return mx;
    }
};
