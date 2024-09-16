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
// void preorder(TreeNode* root,vector<int>& node_values){
//     if(!root)
//         return;
//     node_values.push_back(root->val);
//     preorder(root->left,node_values);
//     preorder(root->right,node_values);
// }
public:
    TreeNode* prev=nullptr;
    void flatten(TreeNode* root) {
        // using extra space by storing node in a vector
        // if(!root)
        //     return;
        // vector<int> node_values;
        // preorder(root,node_values);
        // int n=node_values.size(),i=0;
        // TreeNode* temp=root;
        // while(i<n && temp->right!=NULL){
        //     temp->val=node_values[i];
        //     temp->left=NULL;
        //     temp=temp->right;
        //     i++;
        // }
        // temp->val=node_values[i],temp->left=nullptr;
        // i++;
        // while(i<n){
        //     TreeNode* newNode=new TreeNode(node_values[i]);
        //     temp->right=newNode;
        //     temp=temp->right;
        //     i++;
        // }
        // above code is correct but no need to create new node this can be done recursively
        if(root==nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->left=NULL;
        root->right=prev;
        prev=root;
    }
};