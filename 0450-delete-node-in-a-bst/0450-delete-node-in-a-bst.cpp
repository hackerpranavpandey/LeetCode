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
    TreeNode* delete_root(TreeNode* root){
        // when right tree is null
        if(!root->right)
            return root->left;
        // case when left subtree is empty
        else if(!root->left)
            return root->right;
        // when both subtree is not null
        TreeNode* temp=root->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        temp->left=root->left;
        return root->right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp=root;
        // check if node with value key exist if not then return root
        while(temp!=NULL){
            if(temp->val==key)
                break;
            if(temp->val > key)
                temp=temp->left;
            else
                temp=temp->right;
        }
        if(temp==NULL)
            return root;
         if(root->val==key){
            return delete_root(root);
        }
        // else use the helper function and then make its left subtree 
        // pointed at right subtree leftmost node left
        temp=root;
        TreeNode* parent=NULL;
        while(temp!=NULL && temp->val!=key){
            parent=temp;
            if(temp->val>key)
                temp=temp->left;
            else
                temp=temp->right;
        }
        if(parent->left==temp)
            parent->left=delete_root(temp);
        else
            parent->right=delete_root(temp);
        return root;
    }
};