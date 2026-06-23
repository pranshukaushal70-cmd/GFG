class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        vector<int> ans;
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            ans.push_back(temp);
        }
        for(int x : ans){
            st.push(x);
        }
    }
};
