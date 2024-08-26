/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void nAry_postorder(Node* root,vector<int>& ans){
        if(!root)
            return;
        // recursive call for all childs
        for(Node* child:root->children){
            nAry_postorder(child,ans);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        if(root==NULL)
            return {};
        vector<int> ans;
        nAry_postorder(root,ans);
        return ans;
    }
};