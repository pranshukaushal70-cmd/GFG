class Solution {
private:

    Node* bfsToMapParents(Node* root,
                          unordered_map<Node*, Node*>& parent_track,
                          int target) {

        queue<Node*> q;
        q.push(root);
        Node* res = NULL;
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current->data == target)
                res = current;
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
        return res;
    }

    int findMaxDistance(unordered_map<Node*, Node*>& parent_track,
                        Node* targetNode) {
        queue<Node*> q;
        q.push(targetNode);
        unordered_map<Node*, bool> visited;
        visited[targetNode] = true;
        int maxi = 0;
        while (!q.empty()) {
            int size = q.size();
            int flag = 0;
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                if (current->left && !visited[current->left]) {
                    flag = 1;
                    visited[current->left] = true;
                    q.push(current->left);
                }
                if (current->right && !visited[current->right]) {
                    flag = 1;
                    visited[current->right] = true;
                    q.push(current->right);
                }
                if (parent_track[current] &&
                    !visited[parent_track[current]]) {

                    flag = 1;
                    visited[parent_track[current]] = true;
                    q.push(parent_track[current]);
                }
            }
            if (flag)
                maxi++;
        }
        return maxi;
    }

public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_track;
        Node* targetNode =
            bfsToMapParents(root, parent_track, target);
        return findMaxDistance(parent_track, targetNode);
    }
};
