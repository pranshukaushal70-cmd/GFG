class Solution {
public:
    int closest3Sum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int closest = arr[0] + arr[1] + arr[2];
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = arr[i] + arr[l] + arr[r];
                if (abs(target - sum) < abs(target - closest) ||
                    (abs(target - sum) == abs(target - closest) && sum > closest)) {
                    closest = sum;
                }
                if (sum == target) return sum;
                else if (sum < target) l++;
                else r--;
            }
        }
        return closest;
    }
};
