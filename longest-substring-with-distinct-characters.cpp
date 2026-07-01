class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int> level(256, -1);
        int n=s.size();
        int l=0;
        int r=0;
        int len=0;
        int maxlen=0;
        while(r<n){
            if(level[s[r]] != -1){
                if(level[s[r]]>=l){
                    l=level[s[r]]+1;
                }
            }
            len=r-l+1;
            maxlen=max(len, maxlen);
            level[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};
