//
// Created by Tong Xue on 2019-08-14.
//

#include <iostream>
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),  next(NULL) {}
};
using namespace std;
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (head) {
            ListNode *t = head->next;
            cur = dummy;
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = t;
        }
        return dummy->next;
    }
};
void print(ListNode* head){
    ListNode* p = head;
    while(p){
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}
void push(ListNode* head, int val){
    ListNode* p = head;
    while(p->next){
        p = p->next;
    }
       p->next = new ListNode(val);
}
int main(){
    ListNode* head = new ListNode(6);
    push(head,12);
    push(head,5);
    push(head, 3);
    push(head, 1);
    push(head, 8);
    push(head, 7);

    Solution s;
    head = s.insertionSortList(head);
    print(head);
}