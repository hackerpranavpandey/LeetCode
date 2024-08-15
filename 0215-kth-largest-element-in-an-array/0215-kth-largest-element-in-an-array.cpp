class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // so without sorting the we need to do it either O(n^2)
        // else priority queue
        priority_queue<int> pq;
        for(int num:nums){
            pq.emplace(num);
        }
        int j=0;
        while(j<k-1){
            pq.pop();
            j++;
        }
        return pq.top();
    }
};