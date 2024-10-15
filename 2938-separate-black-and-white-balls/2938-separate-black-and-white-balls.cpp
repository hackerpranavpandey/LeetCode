class Solution {
public:
    long long minimumSteps(string s) {
        // only adjacent swaps are allowed
        // int n=s.size();
        // int i=0,j=n-1;
        // long long countSwap=0;
        // while(i<j){
        //     while(i<j){
        //         if(s[i]=='0')
        //             i++;
        //         else
        //             break;
        //     }
        //     while(i<j){
        //         if(s[j]=='1')
        //             j--;
        //         else
        //             break;
        //     }
        //     if(i<j){
        //         swap(s[i],s[j]);
        //         countSwap++;
        //         i++,j--;
        //     }
        // }
        // return countSwap;
        long long swapCount=0;
        int n=s.size();
        int j=n-1,numZero=0;
        while(j>=0){
            if(s[j]=='0')
                numZero++;
            else
                swapCount+=numZero;
            j--;
        }
        return swapCount;
    }
};