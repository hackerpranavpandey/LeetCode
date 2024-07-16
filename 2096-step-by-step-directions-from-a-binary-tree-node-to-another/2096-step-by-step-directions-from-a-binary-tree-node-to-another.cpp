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
    // this function will return the common ancestor of value t1 and t2
private:
    TreeNode* common_ancestor(TreeNode* node,int t1,int t2){
        if(node==NULL)
            return NULL;
        if(node->val==t1 || node->val==t2)
            return node;
        TreeNode* left=common_ancestor(node->left,t1,t2);
        TreeNode* right=common_ancestor(node->right,t1,t2);
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return node;        
    }
    // this willl return path from root to node with value t
    bool find_path(TreeNode* node,int t,string& path){
        if(node==NULL)
            return false;
        if(node->val==t)
            return true;
        path.push_back('L');
        if(find_path(node->left,t,path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(find_path(node->right,t,path)){
            return true;
        }
        path.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // find common ancestor for both of the node
        TreeNode* ancestor=common_ancestor(root,startValue,destValue);
        string p1;
        find_path(ancestor,startValue,p1); // path 1
        string p2;
        find_path(ancestor,destValue,p2); // path 2
        string ans="";
        int l1=p1.size();   
        ans.append(l1,'U');       // for p1 just move U to reach ancestor
        ans.append(p2);
        return ans;
    }
};