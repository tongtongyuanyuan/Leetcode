//
// Created by Tong Xue on 2019-08-23.
//
#include<iostream>
using namespace std;
class DoubleLinkedlist1{
    class Node{
    public:
        int val;
        Node* next;
        Node* prev;
        Node(int v, Node* next, Node* prev) : val(v), next(next), prev(prev){}
    };
    Node* head;
    Node* tail;
public:
    DoubleLinkedlist1() : head(nullptr), tail(nullptr) {}
    ~DoubleLinkedlist1(){}

    void addEnd(int v) { //O(1)
        Node* temp = new Node(v, nullptr, tail);
//        temp->val = v;
//        temp->next = nullptr;
//        temp->prev = tail;
        if(tail == nullptr){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }

    void addStart(int v){
        Node* temp = new Node(v,head,nullptr);
//        temp->val = v;
//        temp->next = head;
//        temp->prev = nullptr;
        if(head == nullptr){
            head = tail = temp;
        }else{
            head->prev = temp;
            head = temp;
        }
    }

    void removeStart() {
        if(head == nullptr)
            return;
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    bool isEmpty(){
        return head = nullptr;
    }

    void removeEnd(){
        if(tail == nullptr)
            return;
        if(head == tail){
            delete head;
            head = tail = nullptr;
        }
        Node* secondToLast = tail->prev;
        delete tail;
        secondToLast->next = nullptr;
    }

    int get(int idx) {
        Node *p = head;
        for (; idx > 0 && p != nullptr; idx--, p = p->next);
        if (p == nullptr)
            throw "Diediedie";
        return p->val;
    }

    void insertAfter(Node* p, int v){
        //p->next = new Node(v, p->next,p);
        Node* q = p->next;
//        temp->val = v;
//        temp->next = q;
//        temp->prev = p;
        Node* temp = new Node(v, q, p);
        p->next = temp;
        q->prev = temp;
    }

    void insertBefore(Node* p, int v) {
        if (p->prev == nullptr) {
            head = new Node(v, p, nullptr); //p前面建立个head
            p->prev = head;
            return;
        }
        insertAfter(p->prev, v);
//        Node* temp = new Node();
//        Node* q = p->prev;
//        temp->val = v;
//        temp->next = p;
//        temp->prev = q;
//        p->prev = temp;
//        q->next = temp;
    }

friend ostream &operator << (ostream &s, const DoubleLinkedlist1& list){
        for(Node* p = list.head; p != nullptr; p = p->next)
            s << p->val << ' ';
        return s;
    }
};
int main(){
    DoubleLinkedlist1 list;
    list.addEnd(5);
    list.addStart(8);
    list.addEnd(7);
    list.addEnd(6);
    list.addStart(2);
    list.addStart(6);
    list.removeEnd();
    list.removeStart();
    //list.get(5);
    cout << list << '\n';
}