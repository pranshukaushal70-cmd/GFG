class Solution {
	public:
	vector<int> parent, rank_;
	int find(int x) {
		if (parent[x] != x)
			parent[x] = find(parent[x]);
		return parent[x];
	}
	bool unite(int x, int y) {
		int px = find(x), py = find(y);
		if (px == py)
			return false;
		if (rank_[px] < rank_[py]) {
			parent[px] = py; 
		}
		else if (rank_[py] < rank_[px]) {
			parent[py] = px; 
		}
		else {
			parent[py] = px; 
			rank_[px]++; 
		}
		return true;
	}
	int kruskalsMST(int V, vector<vector<int>> &edges) {
		parent.resize(V);
		rank_.assign(V, 0);
		for (int i = 0; i < V; i++)
			parent[i] = i;
		sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
			return a[2] < b[2];
		});
		int mstWeight = 0, edgesUsed = 0;
		for (auto& e : edges) {
			int u = e[0], v = e[1], w = e[2];
			if (unite(u, v)) {
				mstWeight += w;
				edgesUsed++;
				if (edgesUsed == V - 1)
					break;
			}
		}
		return mstWeight;
	}
};
