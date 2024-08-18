class Solution {
public:
    int nthUglyNumber(int n) {
        // so start from 1 now whatever ugly number comes has to be miltiple of 2 3 or 5
        priority_queue<long,vector<long>,greater<long>> ugly_numbers;
        ugly_numbers.emplace(1);
        unordered_set<long long> ugly_seen;
        // 1 is already there so need to do only n-1 times
        for(int i=0;i<n-1;i++){
            long long ugly_first=ugly_numbers.top();
            ugly_numbers.pop();
            long long ugly_1=ugly_first*2,ugly_2=ugly_first*3,ugly_3=ugly_first*5;
            if(ugly_seen.find(ugly_1)==ugly_seen.end()){
                ugly_numbers.push(ugly_1);
                ugly_seen.emplace(ugly_1);
            }
            if(ugly_seen.find(ugly_2)==ugly_seen.end()){
                ugly_numbers.push(ugly_2);
                ugly_seen.emplace(ugly_2);
            }
            if(ugly_seen.find(ugly_3)==ugly_seen.end()){
                ugly_numbers.push(ugly_3);
                ugly_seen.emplace(ugly_3);
            }
        }
        return static_cast<int>(ugly_numbers.top());
    }
};