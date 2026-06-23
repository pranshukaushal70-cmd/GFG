class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        vector<int> ans;
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        for(int x : ans){
            st.push(x);
        }
    }
};
