class Solution {
private:
    // this function will return number that can be prepared till day
    int number_of_bouquet(vector<int> bloomDay, int days, int k){
        int ans=0; // this is final variable jo batayega ki dyas tak kitne banaye ja sakte hai
        int count=0;
        for(auto it:bloomDay){
            // since it has to be adjacent then if bloomDay[i]<=days then only increase count by 1
            if(it<=days){
                count++;
            }
            // else the adjacency is breaked so count=0;
            else{
                count=0;
            }
            // now if count reached k which is number of adjacent flower required then ans++
            if(count==k){
                ans+=1;
                count=0; // do this to restart
            }
        }
        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // idea aasam hai
        // har day tak kitne bouquest banaye jaa sate hai nikal lo upar function ke madad se
        // phir check karo inme se sabse kam din kya hai jisme m se jayada ban jaye
        int n=bloomDay.size();
        // ye code sahi hai but linear search hai binary search lagao
        // int min_days=INT_MAX;
        // for(int i=0;i<n;i++){
        //     if(number_of_bouquet(bloomDay,bloomDay[i],k)>=m){
        //         min_days=min(min_days,bloomDay[i]);
        //     }
        // }
        // if(min_days==INT_MAX)
        //     return -1;
        int min_days=-1;
        int start=0;
        int end=0;
        for(int n:bloomDay){
            end=max(end,n);
        }
        // ab simple binary search lagao aur agar value present hai tab mil hi jaega
        while(start<=end){
            int mid=(start+end)/2;
            if(number_of_bouquet(bloomDay,mid,k)>=m){
                min_days=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return min_days;
    }
};