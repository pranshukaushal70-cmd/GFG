class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int l = 0, r = 0;
        int distinct = 0;
        int ans = -1;
        while (r < n) {
            if (freq[s[r] - 'a'] == 0)
                distinct++;
            freq[s[r] - 'a']++;
            while (distinct > k) {
                freq[s[l] - 'a']--;
                if (freq[s[l] - 'a'] == 0)
                    distinct--;
                l++;
            }
            if (distinct == k) {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};
