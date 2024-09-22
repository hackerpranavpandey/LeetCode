class Solution {
private:
    int count_step(int n,long t_1,long t_2){
        int step=0;
        while(t_1<=n){
            step+=min((long)(n+1),t_2)-t_1;
            t_1*=10;
            t_2*=10;
        }
        return step;
    }
public:
    // below is just using the recursive method but need tries conept
    // int count=0;
    // void solve(int t,int n,int& ans,int k){
    //     if(t>n)
    //         return;
    //     ans=t,count++;
    //     if(count==k)
    //         return;
    //     for(int i=0;i<=9;i++){
    //         if(count<k)
    //             solve(t*10+i,n,ans,k);
    //         else
    //             break;
    //     }
    // }
    int findKthNumber(int n, int k) {
        // deriving inspiration from previous question
        // but it will exceed time limit even if only using a variable count
        // so it is simple to use tries data structure for this kind of tasks
        // int ans=0;
        // for(int i=1;i<=9;i++){
        //     if(count<k)
        //         solve(i,n,ans,k);
        //     else
        //         break;
        // }
        // return ans;
        int curr=1;
        k--;
        int step;
        while(k>0){
            step=count_step(n,curr,curr+1);
            if(step<=k)
                curr++,k-=step;
            else{
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};