class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        if (start == end) return 0;
        vector<bool> visited(1000, false);
        queue<pair<int,int>> q; 
        visited[start] = true;
        q.push({start, 0});
        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            for (int x : arr) {
                int next = (curr * x) % 1000;
                if (next == end) return steps + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }
};
