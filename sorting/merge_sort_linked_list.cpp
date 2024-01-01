/*struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *n) : val(x), next(n) {}
  };
  */

Node* merge(Node* left, Node* right){
    if(!left){
        return right;
    }
    if(!right){
        return left;
    }
    
    Node* result;
    if(left->val<=right->val){
        result = left;
        result->next = merge(left->next, right);
    }
    else{
        result = right;
        result->next = merge(left, right->next);
    }
    
    return result;
}


Node* divide(Node* head){
    if(!head || !head->next){
        return head;
    }
    
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* mid = slow->next;
    slow->next = NULL;
    
    Node* left = divide(head);
    Node* right = divide(mid);
    
    return merge(left, right);
}



class Solution{
	public:
	Node* rearrange(Node* head)
	{
	    return divide(head);
	}
};
