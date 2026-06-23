class Solution {
  public:
    int countStrings(int n) {
        // code here
        int zend=1;
        int oend=1;
        int sum=zend+oend;
        if(n==1) return sum;
        int i=2;
        while(i<=n){
            oend=zend;
            zend=sum;
            sum=zend+oend;
            i++;
        }
        return sum;
    }
};
