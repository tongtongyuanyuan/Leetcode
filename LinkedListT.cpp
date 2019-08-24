                           n                                       //
// Created by Tong Xue on 7/15/19.
//

//insert+remove,single list
#include <iostream>

using namespace std;

class List{
public:
    struct Node{
        int val;
        Node* next;
        Node(int val = 0, Node* next = nullptr): val(val), next(next){}
    };
    Node* head;
    List(): head(nullptr){}

    void insert(int val, int target){
        if(head == nullptr){
            head = new Node(val);
            //return;
        }
        else{
            Node* p = head;
            while(p->val != target && p->next != nullptr){
                p = p->next;
            }
            p->next = new Node(val, p->next);
        }
    }
    int remove(int target){
        if(head == nullptr){
            return -1;
        }
        if(head->val == target){
            head = head->next;
            return target;
        }
        else{
            Node* p = head;
            while(p->next != nullptr && p->next->val != target){
                p = p->next;
            }
            if(p->next == nullptr){
                return -1;
            }
            else{
                p->next = p->next->next;
                return target;
            }
        }
    }

    void print(){
        if(head == nullptr){
            cout << "None" << endl;
            return;
        }
        Node *p = head;
        while(p != nullptr){
            cout << p->val << ' ';
            p = p->next;
        }
        cout << endl;
    }
};




int main(){
    List list;
    list.insert(1, 0);
    list.print();
    list.insert(2, 0);
    list.print();
    list.insert(3, 1);
    list.print();
    list.remove(3);
    list.print();
}