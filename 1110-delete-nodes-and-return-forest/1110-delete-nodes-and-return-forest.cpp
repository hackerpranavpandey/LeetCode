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
    TreeNode* delete_node(TreeNode* node,unordered_set<int> delete_set,vector<TreeNode*>& ans){
        if(!node){
            return NULL;
        }
        // postorder traversal
        node->left=delete_node(node->left,delete_set,ans);
        node->right=delete_node(node->right,delete_set,ans);
        // agar node ko delete karna hai tab uske left aur right ko and=s me push karke NULL return karo
        if(delete_set.find(node->val)!=delete_set.end()){
            if(node->left!=NULL)
                ans.push_back(node->left);
            if(node->right!=NULL)
                ans.push_back(node->right);
            delete node;
            return NULL;
        }
        // nhi to node return karo
        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // so here need to ensure that all child are successfully visited before parents
        // so lets use postorder traversal technique
        unordered_set<int> delete_set(to_delete.begin(),to_delete.end());
        vector<TreeNode*> ans;
        root=delete_node(root,delete_set,ans);
        // case jab root ko delete nhi karna hai
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};