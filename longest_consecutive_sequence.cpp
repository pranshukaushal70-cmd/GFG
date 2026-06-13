class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        int longest=1;
        if(n == 0) return 0;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(arr[i]);
        }
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int count=1;
                int x=it;
                while(st.find(x+1) != st.end()){
                    count++;
                    x=x+1;
                }
                longest=max(longest, count);
            }
        }
        return longest;
    }
};
