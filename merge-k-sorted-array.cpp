class Solution {
  public:
    class Node {
    public:
        int data;
        int row;
        int col;
        Node(int data, int row, int col) {
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };
    
    class Compare {
    public:
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };
    
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int k = mat.size();
        priority_queue<Node*, vector<Node*>, Compare> minHeap;
        for(int i = 0; i < k; i++) {
            minHeap.push(new Node(mat[i][0], i, 0));
        }
        vector<int> ans;
        while(!minHeap.empty()) {
            Node* temp = minHeap.top();
            minHeap.pop();
            int value = temp->data;
            int row = temp->row;
            int col = temp->col;
            ans.push_back(value);
            if(col + 1 < mat[row].size()) {
                minHeap.push(
                    new Node(mat[row][col + 1], row, col + 1)
                );
            }
        }
        return ans;
    }
};
