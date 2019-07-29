//
// Created by Tong Xue on 7/28/19.
//
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if(!headA || !headB) return nullptr;
        ListNode* a = headA, *b = headB;
        while(a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
            return nullptr;
    }
};
int main() {

}
