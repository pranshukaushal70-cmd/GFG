class Solution {
public:
    struct Node {
        int val;
        int row;
        int col;

        Node(int v, int r, int c) {
            val = v;
            row = r;
            col = c;
        }
    };
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->val > b->val;
        }
    };
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        int k = mat.size();
        priority_queue<Node*, vector<Node*>, Compare> minHeap;
        int maxi = INT_MIN;
        for (int i = 0; i < k; i++) {
            minHeap.push(new Node(mat[i][0], i, 0));
            maxi = max(maxi, mat[i][0]);
        }
        int start = minHeap.top()->val;
        int end = maxi;
        while (minHeap.size() == k) {
            Node* temp = minHeap.top();
            minHeap.pop();
            int mini = temp->val;
            int row = temp->row;
            int col = temp->col;
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            if (col + 1 < mat[row].size()) {
                int nextVal = mat[row][col + 1];
                minHeap.push(
                    new Node(nextVal, row, col + 1)
                );
                maxi = max(maxi, nextVal);
            }
        }
        return {start, end};
    }
};
