// class Solution {
// private:
//     // simple dijkstras algorithm that will return the distance between source and target
//     int dijkstra_dist(vector<vector<pair<int,int>>>& adj,int source,int target,int n){
//         vector<int> dist(n,INT_MAX); // will tell distance fraom source node to various nodes
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p_q;
//         p_q.push({0,source});    // weight,node
//         // distance of source to source is 0
//         dist[source]=0;
//         while(!p_q.empty()){
//             auto it=p_q.top();
//             p_q.pop();
//             // traverse each adjacent node of present node
//             for(int i=0;i<adj[it.second].size();i++){
//                 int wt=adj[it.second][i].second,node=adj[it.second][i].first;
//                 if(dist[node]>wt+adj[it.second][i].first){
//                     dist[node]=wt+adj[it.second][i].first;
//                     p_q.push({wt+adj[it.second][i].first,node});
//                 }
//             }
//         }
//         return dist[target];
//     }
// public:
//     const int INF = 2e9;
//     vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
//         // so the idea is to use dijkstras algorithm along with basic logic
//         // check if the path exist or not if exist and greater than target then not possible
//         vector<vector<pair<int,int>>> adj(n);
//         for(vector<int> edge:edges){
//             int u=edge[0],v=edge[1],wt=edge[2];
//             adj[u].push_back({v,wt});      // node ,corresponding weight
//         }
//         int dijkstras_distance=dijkstra_dist(adj,source,destination,n);
//         if(dijkstras_distance<target)
//             return {};
//         bool matchesTarget = ( dijkstras_distance == target);

//         // Step 2: Iterate through each edge to adjust its weight if necessary
//         for (vector<int>& edge : edges) {
//             // Skip edges that already have a positive weight
//             if (edge[2] > 0) continue;

//             // Set edge weight to a large value if current distance matches
//             // target else set to 1
//             edge[2] = matchesTarget ? INF : 1;

//             // Step 3: If current shortest distance does not match target
//             if (!matchesTarget) {
//                 // Compute the new shortest distance with the updated edge
//                 // weight
//                 int newDistance =
//                     dijkstra_dist(adj,source,destination,n);
//                 // If the new distance is within the target range, update edge
//                 // weight to match target
//                 if (newDistance <= target) {
//                     matchesTarget = true;
//                     edge[2] += target - newDistance;
//                 }
//             }
//         }

//         // Return modified edges if the target distance is achieved, otherwise
//         // return an empty result
//         return matchesTarget ? edges : vector<vector<int>>{};
//     }
// };
class Solution {
public:
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int nodeCount,
                                           vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        // Step 1: Compute the initial shortest distance from source to
        // destination
        long long currentShortestDistance =
            runDijkstra(edges, nodeCount, source, destination);

        // If the current shortest distance is less than the target, return an
        // empty result
        if (currentShortestDistance < target) return {};

        bool matchesTarget = (currentShortestDistance == target);

        // Step 2: Iterate through each edge to adjust its weight if necessary
        for (vector<int>& edge : edges) {
            // Skip edges that already have a positive weight
            if (edge[2] > 0) continue;

            // Set edge weight to a large value if current distance matches
            // target else set to 1
            edge[2] = matchesTarget ? INF : 1;

            // Step 3: If current shortest distance does not match target
            if (!matchesTarget) {
                // Compute the new shortest distance with the updated edge
                // weight
                long long newDistance =
                    runDijkstra(edges, nodeCount, source, destination);
                // If the new distance is within the target range, update edge
                // weight to match target
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        // Return modified edges if the target distance is achieved, otherwise
        // return an empty result
        return matchesTarget ? edges : vector<vector<int>>{};
    }

    // Dijkstra's algorithm to find the shortest path distance
    long long runDijkstra(const vector<vector<int>>& edges, int nodeCount,
                          int sourceNode, int destinationNode) {
        // Step 1: Initialize adjacency matrix and distance arrays
        vector<vector<long long>> adjMatrix(nodeCount,
                                            vector<long long>(nodeCount, INF));
        vector<long long> minDistance(nodeCount, INF);
        vector<bool> visited(nodeCount, false);

        // Set the distance to the source node as 0
        minDistance[sourceNode] = 0;

        // Step 2: Fill the adjacency matrix with edge weights
        for (const vector<int>& edge : edges) {
            if (edge[2] != -1) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        // Step 3: Perform Dijkstra's algorithm
        for (int i = 0; i < nodeCount; ++i) {
            // Find the nearest unvisited node
            int nearestUnvisitedNode = -1;
            for (int j = 0; j < nodeCount; ++j) {
                if (!visited[j] &&
                    (nearestUnvisitedNode == -1 ||
                     minDistance[j] < minDistance[nearestUnvisitedNode])) {
                    nearestUnvisitedNode = j;
                }
            }
            // Mark the nearest node as visited
            visited[nearestUnvisitedNode] = true;

            // Update the minimum distance for each adjacent node
            for (int v = 0; v < nodeCount; ++v) {
                minDistance[v] =
                    min(minDistance[v], minDistance[nearestUnvisitedNode] +
                                            adjMatrix[nearestUnvisitedNode][v]);
            }
        }

        // Return the shortest distance to the destination node
        return minDistance[destinationNode];
    }
};