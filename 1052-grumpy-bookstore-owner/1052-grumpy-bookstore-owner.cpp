class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // wo sare customers honge hi jab grumpy[i]==0 
        // but ab minutes jitne consectuive use karna hai taki us period me agar grumpy[i]==1
        // tab bhi customer satisfy ho
        // tab har utne subarray consecutive me jaha grumpy[i]==1 hai waha use karke 
        // kis me maximum aa raha hai usko last me kewla grumpy[i]==0 ke toral sum me add kardo
       int unsatisfied_customers=0; // start karo pehle minutes ko use karke
       for(int i=0;i<minutes;i++){  // usme jaha grumpy[i]==1 hai waha add kardo
           unsatisfied_customers+=(customers[i]*grumpy[i]);
       }
       int n=customers.size();
       int max_possible=unsatisfied_customers;  // isko hi last me add karne hai
       for(int i=minutes;i<n;i++){
           // ab i++ karte jao i-minutes ko agar unsatisfied me add kiya hai tab usko hatao
           // aur agar a bhi grumpy hai tab usko add karo warna chor do
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