class Solution {
	public:
	bool findTriplets(vector<int> &arr) {
		// code here
		int n = arr.size();
		sort(arr.begin(), arr.end());
		for (int i = 0; i<n; i++) {
			if (i>0 && arr[i] == arr[i - 1])
				continue;
			int l = i + 1;
			int r = n - 1;
			while (r>l) {
				int sum = arr[i]+arr[l]+arr[r];
				if (sum>0)
					r--;
				if (sum<0)
					l++;
				if(sum==0) {
					return true;
					l++;
					r--;
				}
			}
		}
		return false;
	}
};
