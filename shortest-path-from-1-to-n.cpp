
class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        dist[1] = 0;
        pq.push({0, 1});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;
            if (dis > dist[node])
                continue;
            for (auto &itr : adj[node]) {
                int adjNode = itr.first;
                int wt = itr.second;
                if (dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        if (dist[n] == 1e9)
            return {-1};
        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);
        return path;
    }
};
