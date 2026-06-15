class Solution {
	public:
	int totalElements(vector<int> &arr) {
		// code here
		unordered_map<int, int> mp;
		int l = 0;
		int maxLen = 0;
		for (int r = 0; r < arr.size(); r++) {
			mp[arr[r]]++;
			while (mp.size() > 2) {
				mp[arr[l]]--;
				if (mp[arr[l]] == 0)
					mp.erase(arr[l]);
				
				l++;
			}
			maxLen = max(maxLen, r - l + 1);
		}
		return maxLen;
	}
};
