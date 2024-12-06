class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> t;
        for(int num:banned){
            t.emplace(num);
        }
        int ans=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(!t.count(i) && (sum+i)<=maxSum)
                ans++,sum+=i;
        }
        return ans;
    }
};