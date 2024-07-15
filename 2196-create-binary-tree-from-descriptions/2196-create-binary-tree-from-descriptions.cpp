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
    // this function will return vector where v[0] is left child and v[1] is right child
    // if -1 then that child is null
// private:
//     vector<int> find_child(vector<vector<int>> description,int parent){
//         vector<int> child(-1,-1);
//         for(vector<int> v:description){
//             if(v[0]==parent){
//                 if(v[2]==1)
//                     child[0]=v[1];
//                 else
//                     child[1]=v[1];
//             }
//         }
//         return child;
//     }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // node that is not child of any node is root node
        unordered_set<int> child_collection;
        unordered_map<int,TreeNode*> nodeMap;
        for(auto it:descriptions){
            int parent=it[0];
            int child=it[1];
            bool left_child=it[2];
            if(nodeMap.find(parent)==nodeMap.end()){
                nodeMap[parent]=new TreeNode(parent);
            }
            if(nodeMap.find(child)==nodeMap.end()){
                nodeMap[child]=new TreeNode(child);
            }
            if(left_child==true)
                nodeMap[parent]->left=nodeMap[child];
            else
                nodeMap[parent]->right=nodeMap[child];
            child_collection.insert(child);
        }
        for(auto it:nodeMap){
            if(child_collection.find(it.first)==child_collection.end())
                return nodeMap[it.first];
        }
        return NULL;
    }
};