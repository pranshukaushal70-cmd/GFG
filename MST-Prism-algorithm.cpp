class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }
        vector<bool> visited(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0}); 
        int mstWeight = 0;
        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();
            if (visited[u]) continue; 
            visited[u] = true;
            mstWeight += wt;
            for (auto& [v, w] : adj[u]) {
                if (!visited[v]) {
                    pq.push({w, v});
                }
            }
        }
        return mstWeight;
    }
};
