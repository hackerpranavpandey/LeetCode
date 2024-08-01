class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        //robot has to travel all rows between and all columns between startPos and homePos
        //add the cost for both of them
        int ans=0;
        int current_row=startPos[0];
        int home_row=homePos[0];
        int current_col=startPos[1];
        int home_col=homePos[1];
        // travel down
        if(current_row<home_row){
            for(int i=current_row+1;i<=home_row;i++){
                ans+=rowCosts[i];
            }
        }
        // if travel up
        else{
            for(int i=current_row-1;i>=home_row;i--){
                ans+=rowCosts[i];
            }
        }
        // column cost
        if(current_col<home_col){
            for(int i=current_col+1;i<=home_col;i++){
                ans+=colCosts[i];
            }
        }
        // if travel right
        else{
            for(int i=current_col-1;i>=home_col;i--){
                ans+=colCosts[i];
            }
        }
        // if travel left
        return ans;
    }
};