class Solution {
public:
    bool isUgly(int n) {
        // base case
        if(n==2 || n==3 || n==5)
            return true;
        // it should be postive not even equal to 0
        else if(n<=0)
            return false;
        // int start=2;
        // while(start<=5 && n>1){
        //     if(n%start==0){
        //         n/=start;
        //     }
        //     else
        //         start+=1;
        // }
        // if(n>1)
        //     return false;
        // return true;
        // above is correct but not a good way to write code
        // divide it will 2 till divisible
        while(n%2==0)
            n=n/2;
        while(n%3==0)
            n=n/3;
        while(n%5==0)
            n=n/5;
        if(n!=1)
            return false;
        return true;
    }
};