class Solution {
public:
    bool isUgly(int n) {
        // base case
        if(n==2 || n==3 || n==5)
            return true;
        else if(n<=0)
            return false;
        int start=2;
        while(start<=5 && n>1){
            if(n%start==0){
                n/=start;
            }
            else
                start+=1;
        }
        if(n>1)
            return false;
        return true;
    }
};