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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // case when the root is itself null then simply create a newNode
        // return the new created node
        if(root==NULL){
            TreeNode* newNode= new TreeNode(val);
            return newNode;
        }
        // now there can be multiple binary tree possible but trying to insert at leaf node is simple
        // and works well as there is simple intuition involved
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->val>val){
                if(temp->left==NULL){
                    TreeNode* newNode= new TreeNode(val);
                    temp->left=newNode;
                    break;
                }
                else
                    temp=temp->left;
            }
            else{
                if(temp->right==NULL){
                    TreeNode* newNode=new TreeNode(val);
                    temp->right=newNode;
                    break;
                }
                else
                    temp=temp->right;
            }
        }
        return root;
    }
};