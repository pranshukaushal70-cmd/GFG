class Solution {
  private:

    void markParents(Node* root,
                     unordered_map<Node*, Node*>& parent_track) {

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    Node* findTarget(Node* root, int target) {
        if (!root) return NULL;
        if (root->data == target)
            return root;
        Node* left = findTarget(root->left, target);
        if (left) return left;
        return findTarget(root->right, target);
    }

  public:
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        unordered_map<Node*, Node*> parent_track;
        markParents(root, parent_track);
        Node* targetNode = findTarget(root, target);
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int curr_level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (curr_level == k)
                break;
            curr_level++;
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] &&
                    !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(), ans.end()); // GFG requires sorted output
        return ans;
    }
};
