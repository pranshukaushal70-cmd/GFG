class Solution {
  public:
  
    void rotateLeft(string &s, int k) {
        int n = s.size();
        k = k % n;
        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
    }
    
    void rotateRight(string &s, int k) {
        int n = s.size();
        k = k % n;
        reverse(s.begin() + (n - k), s.end());
        reverse(s.begin(), s.begin() + (n - k));
        reverse(s.begin(), s.end());
    }

    bool isRotated(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;

        string left = s1;
        string right = s1;

        rotateLeft(left, 2);
        rotateRight(right, 2);

        return (left == s2 || right == s2);
    }
};
