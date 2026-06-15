class Solution {
  public:
    int minValue(Node* root) {
        // code here
        if(root==NULL) return 0;
        while(root->left!= NULL){
            root=root->left;
        }
        return root->data;
    }
};
