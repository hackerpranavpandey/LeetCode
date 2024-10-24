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
    bool flip(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return true;
        else if((!root1 && root2) || (root1 && !root2))
            return false;
        else if(root1->val != root2->val)
            return false;
        bool swapNotReq = flip(root1->left, root2->left) && flip(root1->right, root2->right);
        bool swapReq = flip(root1->left, root2->right) && flip(root1->right, root2->left);
        return swapNotReq || swapReq;
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // damn iterarive way of solving but its too long
        // but recursive way is too easy
        // if(!root1 && !root2)
        //     return true;
        // if((!root1 && root2) || (root1 && !root2))
        //     return false;
        // queue<TreeNode*> t1,t2;
        // t1.push(root1);
        // t2.push(root2);
        // while(!t1.empty() && !t2.empty()){
        //     int n=t1.size();
        //     if(n!=t2.size())
        //         return false;
        //     for(int i=0;i<n;i++){
        //         TreeNode* temp1=t1.front();
        //         TreeNode* temp2=t2.front();
        //         t1.pop();
        //         t2.pop();
        //         if(temp1->val!=temp2->val)
        //             return false;
        //         if(temp1->left && temp1->right){
        //             if(!temp2->left || !temp2->right)
        //                 return false;
        //             else if(temp1->left->val == temp2->left->val && temp1->right->val == temp2->right->val){
        //                 t1.push(temp1->left),t1.push(temp1->right),t2.push(temp2->left),t2.push(temp2->right);
        //             }
        //             else if(temp1->left->val == temp2->right->val && temp1->right->val == temp2->left->val){
        //                 TreeNode* t=temp2->right;
        //                 temp2->right=temp2->left;
        //                 temp2->left=t;
        //                 t1.push(temp1->left),t1.push(temp1->right),t2.push(temp2->left),t2.push(temp2->right); 
        //             }
        //             else
        //                 return false;
        //         }
        //         else if(temp1->left && !temp1->right){
        //             if((temp2->left && temp2->right) || (!temp2->left && !temp2->right))
        //                 return false;
        //             else if(temp2->left && !temp2->right){
        //                 if(temp1->left->val != temp2->left->val)
        //                     return false;
        //                 t1.push(temp1->left);
        //                 t2.push(temp2->left);
        //             }
        //             else{
        //                 if(temp1->left->val != temp2->right->val)
        //                     return false;
        //                 temp2->left=temp2->right;
        //                 temp2->right=NULL;
        //                 t1.push(temp1->left);
        //                 t2.push(temp2->left);
        //             }
        //         }
        //         else if(!temp1->left && temp1->right){
        //             if((temp2->left && temp2->right) || (!temp2->left && !temp2->right))
        //                 return false;
        //             else if(!temp2->left && temp2->right){
        //                 if(temp1->right->val != temp2->right->val)
        //                     return false;
        //                 t1.push(temp1->right);
        //                 t2.push(temp2->right);
        //             }
        //             else{
        //                 if(temp1->right->val != temp2->left->val)
        //                     return false;
        //                 temp2->right=temp2->left;
        //                 temp2->left=NULL;
        //                 t1.push(temp1->right);
        //                 t2.push(temp2->right);
        //             }
        //         }
        //         else if(temp2->left || temp2->right)
        //             return false;
        //     }
        // }
        // if(t1.size()!=t2.size())
        //     return false;
        // return true;
        return flip(root1,root2);
    }
};