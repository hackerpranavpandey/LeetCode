class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows=points.size(),cols=points[0].size();
        // try simple dp and store max points till index i and j in dp[i][j]
        // long long dp[rows][cols];
        // for(int i=0;i<cols;i++){
        //     dp[0][i]=points[0][i];
        // }
        // for(int i=1;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         long long max_points=INT_MIN;
        //         for(int k=0;k<cols;k++)
        //             max_points=max(max_points,dp[i-1][k]+points[i][j]-abs(j-k));
        //         dp[i][j]=max_points;
        //     }
        // }
        // long long ans=INT_MIN;
        // for(int k=0;k<cols;k++)
        //     ans=max(ans,dp[rows-16][k]);
        // return ans;
        // above logic is correct but exceeds time limit
        // so now the idea is to maintain a vector that store the maxpoints for row
        // maintain a prev_row vector that tell the maximum till last row
        // logic simple hai ki left se aaoge tab kitna lekar aaoge aur right se aaoge tab kitna
        vector<long long> prev_row(cols,-1);
        // doing it for first row
        for(int i=0;i<cols;i++){
            prev_row[i]=points[0][i];
        }
        for(int i=1;i<rows;i++){
            vector<long long> left(cols,-1),right(cols,-1);
            left[0]=prev_row[0];
            for(int j=1;j<cols;j++){
                left[j]=max(left[j-1]-1,prev_row[j]);
            }
            right[cols-1]=prev_row[cols-1];
            for(int j=cols-2;j>=0;j--){
                right[j]=max(right[j+1]-1,prev_row[j]);
            }
            // at end check which of three ways of coming gives max value
            vector<long long> curr_row(cols,-1);
            for(int j=0;j<cols;j++){
                // ya phir upar se aao ya phir left ya phir right se
                curr_row[j]=points[i][j]+max(left[j],right[j]);
            }
            //make prev_row to current
            prev_row=curr_row;
        }
        long long ans=-1;
        for(int i=0;i<cols;i++){
            ans=max(ans,prev_row[i]);
        }
        return ans;
    }
};