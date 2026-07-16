class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int ex=0;
        int a=n;
        while(a>0){
            int it=a%10;
            ex+=pow(it, 3);
            a=a/10;
        }
        return ex==n;
    }
};
