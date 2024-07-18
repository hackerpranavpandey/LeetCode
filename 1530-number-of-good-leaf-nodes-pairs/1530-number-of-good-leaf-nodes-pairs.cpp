#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void convert_to_graph(TreeNode* curr, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& graph, unordered_set<TreeNode*>& leaf_node) {
        if (curr == NULL)
            return;
        if (curr->left == NULL && curr->right == NULL)
            leaf_node.insert(curr);
        if (prev != NULL) {
            graph[curr].push_back(prev);
            graph[prev].push_back(curr);
        }
        convert_to_graph(curr->left, curr, graph, leaf_node);
        convert_to_graph(curr->right, curr, graph, leaf_node);
    }
public:
    int countPairs(TreeNode* root, int distance) {
        // first let us convert this to a bidirectional graph
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leaf_node;
        convert_to_graph(root, NULL, graph, leaf_node);
        // now using bfs for each of leaf node
        int ans = 0;
        for (auto leaf : leaf_node) {
            // so we will use basic bfs traversal and get the neighbors of each node
            // go to each neighbor, add it to queue and visited set
            queue<pair<TreeNode*, int>> q; // pair of node and current distance
            unordered_set<TreeNode*> visited;
            q.push({leaf, 0});
            visited.insert(leaf);
            while (!q.empty()) {
                auto [curr, dist] = q.front();
                q.pop();
                if (dist > 0 && leaf_node.find(curr) != leaf_node.end() && curr != leaf) {
                    ans++;
                }
                if (dist < distance) {
                    for (auto neighbor : graph[curr]) {
                        if (visited.find(neighbor) == visited.end()) {
                            q.push({neighbor, dist + 1});
                            visited.insert(neighbor);
                        }
                    }
                }
            }
        }
        ans /= 2; // each pair is counted twice
        return ans;
    }
};
