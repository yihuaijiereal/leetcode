#include "leet.h"

class Solution
{
public:
    ListNode *deleteDup(ListNode *head){
        if(!head||!head->next) return head;
        ListNode *p = head->next;
        if(head->val == p->val){
            while(p&&head->val==p->val){
                ListNode *tmp = p;
                p = p->next;
                delete tmp;
            }
            delete head;
            return deleteDup(p);
        }else{
            head->next = deleteDup(head->next);
            return head;
        }
    }

    ListNode *deleteDup2(ListNode *head){
        if(head == nullptr) return head;

        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode *prev = &dummy,*cur = head;
        while(cur != nullptr){
            bool duplicated = false;
            while(cur->next!=nullptr&&cur->val == cur->next->val){
                duplicated = true;
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            if(duplicated){
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
                continue;
            }
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = cur;
        return dummy.next;
    }
};

int main(){

}
