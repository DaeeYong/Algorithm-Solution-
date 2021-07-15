bool hasCycle(struct ListNode *head) {
    struct ListNode* turtle;
    struct ListNode* rabbit;
    turtle = head;
    rabbit = head;
    
    while(turtle !=NULL && rabbit != NULL){
        
        if(rabbit->next == NULL) return false;
        rabbit = rabbit->next->next;
        turtle = turtle->next;
        if(turtle == rabbit) return true;
    }
    return false;
}