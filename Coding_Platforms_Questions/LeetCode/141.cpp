class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast){
            fast=fast->next;
            if(fast){
                fast=fast->next;
                if(fast==slow){
                    return true;
                }
                slow=slow->next;
                if(fast==slow){
                    return true;
                }
            }
        }
        return false;
    }
};