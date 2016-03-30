#include "leet.h"

class Solution{
public:
    ListNode *add(ListNode *l1,ListNode *l2){
        ListNode dummy(-1); //head
        int carry = 0;
        ListNode *prev = &dummy;
        for(ListNode *pa = l1,*pb = l2;
            pa!=nullptr||pb!=nullptr;
            pa = pa==nullptr?nullptr:pa->next,
            pb = pb==nullptr?nullptr:pb->next,
            prev = prev->next){
            const int ai = pa==nullptr?0:pa->val;
            const int bi = pb==nullptr?0:pb->val;

            const int value = (ai+bi+carry)%10;
            carry = (ai+bi+carry)/10;
            prev->next = new ListNode(value);
        }
        if(carry>0){
            prev->next = new ListNode(carry);
        }
        return dummy.next; //head was destroyed after function call ,so return head->next
    }

    ListNode *reverseBetween(ListNode *head,int m,int n){
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *prev = &dummy;
        for(int i=0;i<m-1;++i){
            prev = prev->next;
        }

        ListNode * const head2 = prev;

        prev = head2->next;
        ListNode *cur = prev->next;
        for(int i=m;i<n;++i){
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = prev->next;
        }

        return dummy.next;
    }
};
