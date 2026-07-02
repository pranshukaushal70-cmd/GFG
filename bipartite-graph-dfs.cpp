class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>> &adj, vector<int> &color) {
        color[node] = col;
        for (int it : adj[node]) {
            if (color[it] == -1) {
                if (!dfs(it, 1 - col, adj, color))
                    return false;
            } else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color))
                    return false;
            }
        }
        return true;
    }
};
