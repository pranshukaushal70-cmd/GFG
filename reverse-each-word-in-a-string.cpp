class Solution {
public:
    string reverseWords(string &s) {
        string ans = "";
        istringstream ss(s);      
        string word;              
        while (ss >> word) {
            reverse(word.begin(), word.end());
            ans += ans.empty() ? word : " " + word;   
        }
        return ans;
    }
};
