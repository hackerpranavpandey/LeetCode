class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       
       int unsatisfied_sum=0; 
       for(int i=0;i<minutes;i++){ 
           unsatisfied_sum+=(customers[i]*grumpy[i]);
       }
       int n=customers.size();
       int max_sum=unsatisfied_sum;  // isko hi last me add karne hai
       for(int i=minutes;i<n;i++){
           // ab i++ karte jao i-minutes ko agar unsatisfied me add kiya hai tab usko hatao
           // aur agar a bhi grumpy hai tab usko add karo warna chor do
           unsatisfied_sum-=(customers[i-minutes]*grumpy[i-minutes]);
           unsatisfied_sum+=(customers[i]*grumpy[i]);
           max_sum=max(max_sum,unsatisfied_sum);
       }
       int ans=max_sum;
       for(int i=0;i<n;i++){
           ans+=customers[i]*(1-grumpy[i]);
       }
       return ans;
    }
};