class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // int ans=0;
        // int index=0,n=chalk.size();
        // while(k>=0){
        //     k-=chalk[index];
        //     if(k<0){
        //         ans=index;
        //         break;
        //     }
        //     index++;
        //     index=index%n;
        // }
        // above method is correct but it will exceed time limit
        // so another way to think is that chalk sum till any students will be increasing
        // so binary search can be used
        // so need to find the first index where t[i]>k with k=k%t[n-1]
        long long sum=0;
        int n=chalk.size();
        vector<long long> t(n,0);
        for(int i=0;i<n;i++){
            sum+=chalk[i];
            t[i]=sum;
        }
        k=k%t[n-1];
        int start=0,end=n-1,ans=0;
        // find first index where t[index]>k
        while(start<=end){
            int mid=(start+end)/2;
            if(t[mid]>k)
                ans=mid,end=mid-1;
            else
                start=mid+1;
        }
        return ans;
    }
};