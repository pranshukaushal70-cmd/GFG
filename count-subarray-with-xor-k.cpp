class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int xr = 0;
        long cnt = 0;
        for(int x : arr) {
            xr ^= x;
            cnt += mp[xr ^ k];
            mp[xr]++;
        }
        return cnt;
    }
};
