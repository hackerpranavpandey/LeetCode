class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> tanisha;
        for(int t:arr){
            if((t%2!=1 && tanisha.count(t/2)) || (tanisha.count(2*t)))
                return true;
            tanisha.emplace(t);
        }
        return false;
    }
};