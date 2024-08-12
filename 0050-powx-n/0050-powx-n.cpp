class Solution {
public:
    double myPow(double x, int n) {
        // if 2,4 then (2*2)*(2*2) works like 4*4 instead of 2 four times
        // this saves time
        // just need to take care for odd number cases
        // like n=3 and all
        // to handle case of INT_MIN used exp variable since -(-2^31) > INT_MAX
        if(n==0 || x==1)
            return static_cast<double>(1);
        else if(x==0)
            return static_cast<double>(0);
        double ans=1.0;
        long long exp=n;
        if(n<0){
            exp=-exp;
            // divide double with double
            x=1.0/x;
        }
        while(exp>0){
            if(exp%2==1){
                ans=ans*x;
            }
            x*=x;
            exp/=2;
        }
        return ans;
    }
};