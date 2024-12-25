class Solution {
private:
    // bool prime(int num){
    //     if(num>1 && num<=3)
    //         return true;
    //     for(int i=2;i<=sqrt(num);i++){
    //         if(num%i==0)
    //             return false;
    //     }
    //     return true;
    // }
public:
    int countPrimes(int n) {
        // below algorithm is in O(nroot(n))
        // int ans=0;
        // for(int i=2;i<n;i++){
        //     if(prime(i))
        //         ans++;
        // }
        // return ans;
        // Sieve of Eratosthenes
        vector<long long> prime(n,1);
        long long cmp=INT_MAX;
        for(int i=2;i*i<n;i++){
            if(prime[i]){
                for(int j=i*i;j<n;j+=i){
                    prime[j]=0;
                }
            }
        }
        int ans=0;
        for(int i=2;i<n;i++){
            if(prime[i])
                ans++;
        }
        return ans;
    }
};