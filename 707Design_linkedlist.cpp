//
// Created by Tong Xue on 2019-08-23.
//

#include <iostream>
using namespace std;

class MyLinkedList{
private:
    struct Node{
        int val;
        Node* next;
        Node* prev;
        Node(int x, Node* prev = nullptr, Node* next = nullptr) : val(x), prev(prev), next(next) {}
    };
    Node* head;
    Node* tail;
    int size;
public:
    MyLinkedList(){
        head = new Node(-1);
        tail = new Node(-1,head, nullptr);
        head->next = tail;
        size = 0;
    }

    int get(int index){
        if(index < 0 || index >= size) return -1;
        Node* cur = head->next;
        int idx = 0;
        while(idx < index){
            cur = cur->next;
            idx++;
        }
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list.
     * After the insertion, the new node will be the first node of the linked list. */
     void addAtHead(int val){
         Node* cur = new Node(val, head, head->next);
         cur->prev->next = cur;
         cur->next->prev = cur;
         size++;
     }

     void addAtTail(int val){
         Node* cur = new Node(val, tail->prev, tail); //此设计tail和head是dummy node
         cur->prev->next = cur;
         tail->prev = cur;
         ++size;
     }

     /** Add a node of value val before the index-th node in the linked list. If index
     equals to the length of linked list, the node will be appended to the end of linked list.
     If index is greater than the length, the node will not be inserted. */
     void addAtIndex(int index, int val) {
         if (index <= 0) {
             addAtHead(val);
         } else if (index == size) {
             addAtTail(val);
         } else if (index > size) return;
         else{
             Node* p = head->next;
             for(int i = 0; i < index; ++i){
                 p = p->next;
             }
             Node* cur = new Node(val, p->prev, p); //注意是index-th
              cur->prev->next = cur;
              cur->next->prev = cur;
              ++size;
         }
     }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index){
        if(index < 0 || index >= size) return;
        Node* p = head->next;
        for(int i = 0;i < index; ++i) p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        --size;
    }

    void print(){
        if(head == nullptr){
            cout << "Node" << endl;
            return;
        }
        Node* p = head->next;
        while(p!= tail){
            cout << p->val << ' ';
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);
    list.print();
    list.get(1);
    list.print();
    list.deleteAtIndex(1);
    list.print();
    list.get(1);
    list.print();
};

