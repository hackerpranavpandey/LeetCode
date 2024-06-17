class Solution {
public:
    bool judgeSquareSum(int c) {
        int last_index=pow(c,0.5); 
        for(int i=last_index;i>=0;i--){
            int t_1=pow(i,2);
            double t_2=pow(c-t_1,0.5);
            if((t_2-static_cast<int>(t_2))==0)
                return true;
        }
        return false;
    }
};