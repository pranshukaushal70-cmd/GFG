class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixIndex;
        int sum = 0, maxlen = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == k)
                maxlen = i + 1;
            if (prefixIndex.find(sum - k) != prefixIndex.end())
                maxlen = max(maxlen, i - prefixIndex[sum - k]);
            if (prefixIndex.find(sum) == prefixIndex.end())
                prefixIndex[sum] = i;
        }
        return maxlen;
    }
};
