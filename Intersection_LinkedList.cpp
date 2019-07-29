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
            return a;
    }
};

int main() {
    vector<int> common{8, 4, 5};
    vector<int> l1{4, 1};
    vector<int> l2{5, 0, 1};

    ListNode *dummy1 = new ListNode(-1);
    ListNode *dummy2 = new ListNode(-1);
    ListNode *p1 = dummy1;
    ListNode *p2 = dummy2;

    for (auto &l : l1) {
        p1->next = new ListNode(l);
        p1 = p1->next;
    }
    for (auto &l : l2) {
        p2->next = new ListNode(l);
        p2 = p2->next;
    }
    ListNode *inter = p1;
    for (auto &c : common) {
        p1->next = new ListNode(c);
        p1 = p1->next;
    }
    p2->next = inter->next;

    p1 = dummy1->next;
    p2 = dummy2->next;

    Solution S;
    cout << S.getIntersectionNode(p1, p2) -> val << " ";

}
