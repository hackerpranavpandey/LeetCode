class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        int n=s.size();
        goal+=goal;
        for(int i=0;i<n;i++){
            if(s==goal.substr(i,n))
                return true;
        }
        return false;
    }
};