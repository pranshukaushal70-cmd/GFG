class Solution {
  public:
    // Step 1: Inorder traversal to get sorted values
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    void postorderAssign(Node* root, vector<int>& arr, int& idx) {
        if (!root) return;
        postorderAssign(root->left, arr, idx);
        postorderAssign(root->right, arr, idx);
        root->data = arr[idx++]; 
    }
    
    void convertToMaxHeapUtil(Node* root) {
        vector<int> arr;
        inorder(root, arr);
        int idx = 0;
        postorderAssign(root, arr, idx); 
    }
};
