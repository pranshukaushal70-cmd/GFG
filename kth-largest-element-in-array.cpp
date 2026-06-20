class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> &arr, int k) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=arr.size();
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        for(int i=k; i<n; i++){
            if(arr[i]>pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};
