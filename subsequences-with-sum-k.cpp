class Solution {
public:
    vector<vector<int>> memo;
    bool helper(vector<int>& arr, int k, int idx, int sum) {
        if (sum == k)
            return true;
        if (idx == arr.size() || sum > k) 
            return false;
        if (memo[idx][sum] != -1)
            return memo[idx][sum];
        bool result = helper(arr, k, idx + 1, sum + arr[idx]) || 
                      helper(arr, k, idx + 1, sum);
        return memo[idx][sum] = result;
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n = arr.size();
        memo.assign(n, vector<int>(k + 1, -1));
        return helper(arr, k, 0, 0);
    }
};
