class Solution {
public:
    int nthUglyNumber(int n) {
        // so start from 1 now whatever ugly number comes has to be miltiple of 2 3 or 5
        // so using the conventional approach it exceeds the time limit
        // now what we can do is first take 1 then keep on multiplying it with 2,3 and 5
        // now need to do this for all generated ugly numbers but the problem comes with duplicates
        // and also if some bigger comes before smaller
        // so use priority queue as min heap then do this
        // for issue of duplicated push the value after multiplying with 2,3 and 5
        // then insert themm in set
        // after that for next value push only if it is not present in the set
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