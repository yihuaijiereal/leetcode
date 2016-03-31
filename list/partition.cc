#include "leet.h"

class Solution{
public:
    ListNode *partitionList(ListNode *head,int x){
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);

        auto left_cur = &left_dummy;
        auto right_cur = &right_dummy;

        for(ListNode *cur = head; cur!=nullptr; cur = cur->next){
            if(cur->val<x){
                left_cur->next = cur;
                left_cur = cur;
            }else{
                right_cur->next = cur;
                right_cur = cur;
            }
        }
        left_cur->next = right_dummy.next;
        right_cur->next = nullptr;
        return left_dummy.next;
    }
};

int main(){
    ListNode head(9);
    auto cur = &head;
    for(int i=6;i>0;--i){
        cur->next = new ListNode(i);
        cur = cur->next;
        cur->next = nullptr;
    }

    for(int i=11;i>4;--i){
        cur->next = new ListNode(i);
        cur = cur->next;
        cur->next = nullptr;
    }

    for(ListNode *cur = &head;cur!=nullptr;cur = cur->next){
        cout<<cur->val<<" ";
    }

    cout<<endl;
    Solution solution;
    ListNode *r = solution.partitionList(&head,8);
    for(ListNode *cur = r;cur!=nullptr;cur = cur->next){
        cout<<cur->val<<" ";
    }

    cout<<endl;
}
