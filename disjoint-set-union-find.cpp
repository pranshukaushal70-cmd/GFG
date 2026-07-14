class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int z) {
        int px = find(x);
        int pz = find(z);
        if (px != pz)
            parent[px] = pz;
    }
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        vector<int> result;
        for (auto& q : queries) {
            if (q[0] == 1) {
                unite(q[1], q[2]);
            } else {
                result.push_back(find(q[1]));
            }
        }
        return result;
    }
};
