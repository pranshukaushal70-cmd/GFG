class Solution {
public:
    void getPath(Node* root, vector<int>& path, vector<vector<int>>& ans) {
        if (root == NULL)
            return;
        path.push_back(root->data);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
        } else {
            getPath(root->left, path, ans);
            getPath(root->right, path, ans);
        }
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> path;
        getPath(root, path, ans);
        return ans;
    }
};
