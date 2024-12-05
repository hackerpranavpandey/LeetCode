class Solution {
public:
    bool canChange(string start, string target) {
        // first check that the relative ordering must be same
        // after this the logic is simple that in start 'L' index should be after 'L' index in target
        // then only it can move left
        // just opposite for the 'R'
        int n=start.size();
        string s1="",s2="";
        for(int i=0;i<n;i++){
            if(start[i]!='_')
                s1+=start[i];
            if(target[i]!='_')
                s2+=target[i];
        }
        if(s1!=s2)
            return false;
         queue<pair<char, int>> startQueue, targetQueue;

        // Record non-underscore characters and their indices
        for (int i = 0; i < start.size(); i++) {
            if (start[i] != '_') {
                startQueue.push({start[i], i});
            }
            if (target[i] != '_') {
                targetQueue.push({target[i], i});
            }
        }

        // If number of pieces don't match, return false
        if (startQueue.size() != targetQueue.size()) return false;

        // Compare each piece's type and position
        while (!startQueue.empty()) {
            auto [startChar, startIndex] = startQueue.front();
            startQueue.pop();
            auto [targetChar, targetIndex] = targetQueue.front();
            targetQueue.pop();

            // Check character match and movement rules
            if (startChar != targetChar ||
                (startChar == 'L' && startIndex < targetIndex) ||
                (startChar == 'R' && startIndex > targetIndex))
                return false;
        }

        return true;
    }
};