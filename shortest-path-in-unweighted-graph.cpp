class Solution {
	public:
	int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
		// code here
		vector<int> adj[V];
		for (auto &it : edges) {
			int u = it[0];
			int v = it[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> dist(V, -1);
		queue<int> q;
		q.push(src);
		dist[src] = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int nbr : adj[node]) {
				if (dist[nbr] == -1) {
					dist[nbr] = dist[node] + 1;
					q.push(nbr);
				}
			}
		}
		return dist[dest];
	}
};
