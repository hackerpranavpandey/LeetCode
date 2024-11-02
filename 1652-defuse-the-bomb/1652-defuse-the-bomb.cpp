class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n,0);
        if(k==0)
            return ans;
        int t=0;
        if(k>0){
            int index=1;
            while(k>0){
                t+=code[index];
                index=(index+1)%n;
                k--;
            }
            for(int i=0;i<n;i++){
                ans[i]=t;
                t-=code[(i+1)%n];
                t+=code[index];
                index=(index+1)%n;
            }
            return ans;
        }
       else{
           int index=n-1;
           k=abs(k);
           while(k>0){
               t+=code[index];
               index=(index-1);
               if(index==-1)
                   index=n-1;
               k--;
           }
           index=(index+1)%n;
           for(int i=0;i<n;i++){
               ans[i]=t;
               t-=code[index];
               t+=code[i];
               index=(index+1)%n;
           }
           return ans;
       }
    }
};