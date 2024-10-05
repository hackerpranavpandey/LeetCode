class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for(int i=0;i<boxes.size();i++){
            int step=0;
            for(int j=0;j<boxes.size();j++){
                if(i==j)
                    continue;
                step=step+abs(i-j)*(int)(boxes[j]-'0');
            }
            ans.push_back(step);
        }
        return ans;
    }
};