class Solution {
	public:
	int countSubarray(vector<int>& arr, int k) {
		// code here
		int n = arr.size();
		int count = 0;
		for (int i = 0; i<n; i++) {
			long long product = arr[i];
			if (product<k)
				count++;
			for (int j = i + 1; j<n; j++) {
				product *= arr[j];
				if (product<k) {
					count++;
				}
				else
					break;
			}
		}
		return count;
	}
};
