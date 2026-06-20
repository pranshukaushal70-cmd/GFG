class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=arr.size();
        long long ans=0;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            long long merged=a+b;
            ans+=merged;
            pq.push(merged);
        }
        return ans;
    }
};
