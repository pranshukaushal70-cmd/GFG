class Solution {
  private:
    void dfshelper(int node, vector<vector<int>>& adj, int vis[], vector<int>& dfs){
        vis[node]=1;
        dfs.push_back(node);
        for(int it : adj[node]){
            if(!vis[it]) dfshelper(it, adj, vis, dfs);
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> dfs;
        int n=adj.size();
        int vis[n]={0};
        int start=0;
        dfshelper(start, adj, vis, dfs);
        return dfs;
    }
};
