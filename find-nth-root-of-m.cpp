class Solution {
	public:
	int power(int mid, int n, int m) {
		long long ans = 1;
		for (int i = 0; i < n; i++) {
			ans *= mid;
			if (ans > m)
				return 2;
		}
		if (ans == m)
			return 1;
		return 0;
	}
	int nthRoot(int n, int m) {
		int low = 1;
		int high = m;
		if (m == 0 || m == 1)
			return m;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int check = power(mid, n, m);
			if (check == 1)
				return mid;
			else if (check == 0)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return - 1;
	}
};
