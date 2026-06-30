class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        vector<int> ans=arr;
        int n=arr.size();
        sort(ans.begin(), ans.end());
        int count=0;
        for(int i=0; i<n; i++){
            if(ans[0]==arr[i]) break;
            count++;
        }
        return count;
    }
};
