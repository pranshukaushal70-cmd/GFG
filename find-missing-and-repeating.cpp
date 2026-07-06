class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(n + 1, 0);
        int repeat = -1, missing = -1;
        for(int x : arr)
            freq[x]++;
        for(int i = 1; i <= n; i++) {
            if(freq[i] == 2)
                repeat = i;
            else if(freq[i] == 0)
                missing = i;
        }
        return {repeat, missing};
    }
};
