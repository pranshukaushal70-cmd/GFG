class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<pair<int, pair<int,int>>> pq;
        set<pair<int,int>> vis;
        pq.push({a[n-1] + b[n-1], {n-1, n-1}});
        vis.insert({n-1, n-1});
        vector<int> ans;
        while(k-- && !pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int sum = it.first;
            int i = it.second.first;
            int j = it.second.second;
            ans.push_back(sum);
            if(i-1 >= 0 && vis.find({i-1, j}) == vis.end()) {
                pq.push({a[i-1] + b[j], {i-1, j}});
                vis.insert({i-1, j});
            }
            if(j-1 >= 0 && vis.find({i, j-1}) == vis.end()) {
                pq.push({a[i] + b[j-1], {i, j-1}});
                vis.insert({i, j-1});
            }
        }
        return ans;
    }
};
