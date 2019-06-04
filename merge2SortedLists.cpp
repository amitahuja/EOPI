
#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int v;
    Node *next;
};

class List{

    public:
    Node * head;
       List(){
           head = nullptr;
       }


    void addVal(int val){
        Node *n = new Node;

        n->v = val;
        //cout << n->v << " ";
        if(!head){
            head = n;
            n->next = nullptr;
            return;
        }

        n->next = head;
        head = n;
    }

    void reverseList(void){

        Node *curr, *prev, *next;
        prev = nullptr;
        curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

    }

    void printList(void){
        Node *n = head;
        //cout << n << " " << n->next <<  "\n";
        while(n){
            cout << n->v << " ";
            n = n->next;
        }
        cout << "\n";
    }
};

List mergeLists(List l1, List l2){
    Node *h1 = l1.head;
    Node* h2 = l2.head;
    Node * c1 = h1, *c2 = h2,  *mc;
    List nh;
    nh.head = nullptr;
    while(c1 && c2){
        if(c1->v <= c2->v){
            if(!nh.head){
                nh.head = c1;
                mc = nh.head;
            }
            else{
                mc->next = c1;
                mc=mc->next;
            }
            c1 = c1->next;
        }
        else{
            if(!nh.head){
                nh.head = c2;
                mc = nh.head;
            }
            else{
                mc->next = c2;
                mc=mc->next;
            }
            c2 = c2->next;
        }
        //cout << nh.head->next->v << " " << mc->v << " " << c1->v << " " << c2->v << "\n";
    }
    if(!c1 && c2) mc->next = c2;
    if(!c2 && c1) mc->next = c1;
    return nh;


}

int main(){
    List ls, ls2;
    ls.addVal(1);
    ls.addVal(2);
    ls.addVal(3);
    ls.addVal(4);
    ls.addVal(5);
    ls.addVal(20);
    ls2.addVal(5);
    ls2.addVal(6);
    ls2.addVal(7);
    ls2.addVal(8);
    ls2.addVal(9);
    ls2.addVal(10);
    ls.printList();
    ls.reverseList();
    ls2.reverseList();
    ls.printList();
    ls2.printList();
    auto nl = mergeLists(ls, ls2);
    Node *hd = nl.head;
    //cout << hd << " " << hd->v;
    while(hd){
       //cout << hd->v << " ";
       hd = hd->next;
    }
    nl.printList();

}


