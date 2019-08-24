//
// Created by Tong Xue on 2019-08-23.
//
#include <iostream>
using namespace std;

class LinkedList1{
private:
    class Node{
public:
    int val;
    Node* next;
    Node(int v, Node *node) : val(v), next(node) {}
};
    Node *head;
    Node *tail;
public:
    LinkedList1() : head(nullptr), tail(nullptr) {}
    ~LinkedList1() {
        cout << "Detele all nodes " << endl;
        Node* p = head;
        while(p != nullptr){
        Node *temp = p;
        p = p->next;
        delete temp;
        }
    }
    void addEnd(int v) {
        Node *p = new Node(v, nullptr);
        if (head == nullptr) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    void addStart(int v){
        Node *p = new Node(v,nullptr);
        if(head == nullptr) {
            head = tail = p;
    }else{
            p->next = head;
            head = p;
        }
    }

    void removeStart() {
        if(head == tail) {
            Node* temp = head;
            head = tail = nullptr;
            delete temp;
        }else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeBack(){
        if(tail == nullptr) return;
        else if(head == tail) {
            Node* temp = tail;
            tail = head = nullptr;
            delete temp;
        }else{
            Node *temp = tail;
            Node *p = head;
            while(p->next != tail)
                p = p->next;
            tail = p;//当p走到tail位置
            tail->next = nullptr;
            delete temp;
        }
    }
    friend ostream &operator << (ostream &s, const LinkedList1& list) {
        for(Node* p = list.head; p != nullptr; p = p->next) {
            s << p->val << ' ';
        }
        s << endl;
        return s;
    }
};
int main(){
    LinkedList1 list;
    list.addStart(3);
    list.addStart(4);
    list.addEnd(5);
    list.addEnd(8);
    list.removeStart();
    list.removeBack();
    cout << list << '\n';
}