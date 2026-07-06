class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        for (string word : words) {
            for (char ch : word) {
                indegree[ch] = 0;
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string &s1 = words[i];
            string &s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j]].push_back(s2[j]);
                    indegree[s2[j]]++;
                    found = true;
                    break;
                }
            }
            if (!found && s1.size() > s2.size())
                return "";
        }
        queue<char> q;
        for (auto &it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }
        string ans;
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            ans += node;
            for (char neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        if (ans.size() != indegree.size())
            return "";
        return ans;
    }
};
