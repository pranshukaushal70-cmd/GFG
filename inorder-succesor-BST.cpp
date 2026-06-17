class Solution {
public:
    void inorder(Node* root, vector<Node*>& ans) {
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }
    int inOrderSuccessor(Node* root, Node* k) {
        vector<Node*> ans;
        inorder(root, ans);
        
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i]->data == k->data) {
                if (i + 1 < ans.size()) return ans[i + 1]->data; 
                else return -1; 
            }
        }
        return -1;
    }
};
