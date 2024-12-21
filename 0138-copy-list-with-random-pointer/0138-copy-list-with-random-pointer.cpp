/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // this is O(2N) time as well as space we cannot assign random if the node has not been created
        // one way to avoid this is insert newnode in between then traverse again
        unordered_map<Node*,Node*> mpp;
        Node* temp=head;
        while(temp){
            Node* newNode=new Node(temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node* curr=mpp[temp];
            curr->next=mpp[temp->next];
            curr->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};