class Solution {
public:
    int missingNum(vector<int>& arr) {
        long long n = arr.size() + 1;
        long long totalSum = n * (n + 1) / 2;
        long long sum = 0;
        for (int x : arr) {
            sum += x;
        }
        return totalSum - sum;
    }
};
