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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // just using the simple approach 
        // brute force one woth time complexity of N*N
        // so it is like root->left->right
        // so first value preorder vector is going to be the root of the BST that we want
        if(preorder.size()==0) // case when there is no node
            return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        int n=preorder.size();
        for(int i=1;i<n;i++){
            TreeNode* newNode=new TreeNode(preorder[i]);
            TreeNode* parent=NULL;
            TreeNode* temp=root;
            while(temp!=NULL){
                parent=temp;
                if(temp->val>preorder[i])
                    temp=temp->left;
                else
                    temp=temp->right;
            }
            if(parent->val>preorder[i])
                parent->left=newNode;
            else
                parent->right=newNode;
        }
        return root;
    }
};