class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int unsatisfied_customers=0;
       for(int i=0;i<minutes;i++){
           unsatisfied_customers+=(customers[i]*grumpy[i]);
       }
       int n=customers.size();
       int max_possible=unsatisfied_customers;
       for(int i=minutes;i<n;i++){
           unsatisfied_customers-=(customers[i-minutes]*grumpy[i-minutes]);
           unsatisfied_customers+=(customers[i]*grumpy[i]);
           max_possible=max(max_possible,unsatisfied_customers);
       }
       int ans=max_possible;
       for(int i=0;i<n;i++){
           ans+=customers[i]*(1-grumpy[i]);
       }
       return ans;
    }
};