class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int l_1=1,l_2=2;
        int ans=l_1+l_2;
        for(int i=3;i<=n;i++){
            ans=l_1+l_2;
            l_1=l_2,l_2=ans;
        }
        return ans;
    }
};