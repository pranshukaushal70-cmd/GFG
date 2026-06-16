class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int floor=-1;
        while(root){
            if(k>=root->data){
                floor=root->data;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return floor;
    }
};
