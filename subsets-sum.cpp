class Solution {
public:
    void solve(int idx, int sum, vector<int> &arr, vector<int> &ans) {
        if (idx == arr.size()) {
            ans.push_back(sum);
            return;
        }
        sum+=arr[idx];
        solve(idx + 1, sum, arr, ans);
        sum-=arr[idx];
        solve(idx + 1, sum, arr, ans);
    }

    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        solve(0, 0, arr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
