class Solution {
public:
    int minOperations(vector<string>& logs) {
        // only three cases eithere it will go ahead , back or same folder
        int steps_required=0;
        for(string str:logs){
            if(str=="./")
                continue;
            else if(str=="../"){
                if(steps_required>0)
                    steps_required--;   
            }
            else
                steps_required++;
        }
        return steps_required;
    }
};