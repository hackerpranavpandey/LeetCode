// class Solution {
// public:
    // int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // need to maintain the left and right for each of the direction
        // so below code is very simple intuition but without the concept of the obstacles
        // pair<int,int> curr={0,0}; // current postition
        // char curr_dir='N'; // current direction track
        // unordered_map<int,int> row_index,col_index;
        // for(int i=0;i<obstacles.size();i++){
        //     row_index[obstacles[i][0]]=i,col_index[obstacles[i][1]]=i;
        // }
        // for(int i=0;i<commands.size();i++){
        //     // if turn left then direction update
        //     if(commands[i]==-2){
        //         if(curr_dir=='N')
        //             curr_dir='W';
        //         else if(curr_dir=='S')
        //             curr_dir='E';
        //         else if(curr_dir=='E')
        //             curr_dir='N';
        //         else
        //             curr_dir='S';
        //     }
        //     // if turn right then direction update
        //     else if(commands[i]==-1){
        //         if(curr_dir=='N')
        //             curr_dir='E';
        //         else if(curr_dir=='S')
        //             curr_dir='W';
        //         else if(curr_dir=='E')
        //             curr_dir='S';
        //         else
        //             curr_dir='N';
        //     }
        //     // movement update
        //     else{
        //         if(curr_dir=='N'){
        //             if(row_index.find(curr.first)!=row_index.end()){
        //                 int j=row_index[curr.first];
        //                 vector<int> obs_cord=obstacles[j];
        //                 if(curr.second+commands[i]>=obs_cord[1])
        //                     curr.second=obs_cord[1]-1;
        //                 else
        //                     curr.second+=commands[i];
        //             }
        //             else
        //                 curr.second+=commands[i];   
        //         }
        //         else if(curr_dir=='S'){
        //             if(row_index.find(curr.first)!=row_index.end()){
        //                 int j=row_index[curr.first];
        //                 vector<int> obs_cord=obstacles[j];
        //                 if(curr.second+commands[i]<=obs_cord[1])
        //                     curr.second=obs_cord[1]+1;
        //                 else
        //                     curr.second-=commands[i];
        //             }
        //             else
        //                 curr.second-=commands[i];   
        //         }
        //         else if(curr_dir=='E'){
        //             if(col_index.find(curr.second)!=col_index.end()){
        //                 int j=col_index[curr.second];
        //                 vector<int> obs_cord=obstacles[j];
        //                 if(curr.first+commands[i]>=obs_cord[0])
        //                     curr.first=obs_cord[0]-1;
        //                 else
        //                     curr.first-=commands[i];
        //             }
        //             else
        //                 curr.first+=commands[i];   
        //         }
        //         else{
        //             if(col_index.find(curr.second)!=col_index.end()){
        //                 int j=col_index[curr.second];
        //                 vector<int> obs_cord=obstacles[j];
        //                 if(curr.first+commands[i]<=obs_cord[0])
        //                     curr.first=obs_cord[0]+1;
        //                 else
        //                     curr.first-=commands[i];
        //             }
        //             else
        //                 curr.first-=commands[i];   
        //         }
        //     }
        // }
        // return (pow(curr.first,2)+pow(curr.second,2));
    // }
// };
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors: N, E, S, W (clockwise)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; // initially facing north
        pair<int, int> curr = {0, 0}; // current position
        
        // Store obstacles in a set for fast lookup
        set<pair<int, int>> obstacle_set;
        for (const auto& obstacle : obstacles) {
            obstacle_set.insert({obstacle[0], obstacle[1]});
        }
        
        int max_dist = 0;
        
        for (int command : commands) {
            if (command == -2) {
                // Turn left 90 degrees
                dir = (dir + 3) % 4;
            } else if (command == -1) {
                // Turn right 90 degrees
                dir = (dir + 1) % 4;
            } else {
                // Move forward
                for (int step = 0; step < command; ++step) {
                    int next_x = curr.first + directions[dir].first;
                    int next_y = curr.second + directions[dir].second;
                    
                    // Check if the next position is an obstacle
                    if (obstacle_set.find({next_x, next_y}) == obstacle_set.end()) {
                        curr.first = next_x;
                        curr.second = next_y;
                    } else {
                        break; // stop if the next step is an obstacle
                    }
                }
            }
            max_dist = max(max_dist, curr.first * curr.first + curr.second * curr.second);
        }
        
        return max_dist;
    }
};