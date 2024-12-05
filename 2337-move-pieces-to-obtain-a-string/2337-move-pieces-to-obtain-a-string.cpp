class Solution {
public:
    bool canChange(string start, string target) {
        // first check that the relative ordering must be same
        // after this the logic is simple that in start 'L' index should be after 'L' index in target
        // then only it can move left
        // just opposite for the 'R'
        int n=start.size();
        string s1="",s2="";
        vector<int> start_index, target_index;
        for(int i=0;i<n;i++){
            if(start[i]!='_')
                s1+=start[i], start_index.push_back(i);
            if(target[i]!='_')
                s2+=target[i], target_index.push_back(i);
        }
        if(s1!=s2)
            return false;
        for(int i=0;i<s1.size();i++){
            if((s1[i]=='L' && start_index[i]<target_index[i]) || (s1[i]=='R' && start_index[i]>target_index[i])) 
                return false;
        }
        return true;
    }
};