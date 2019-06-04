
    

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

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
};

void AppendNode(shared_ptr<ListNode<int>> *node, shared_ptr<ListNode<int>> * tail){
    (*tail)->next =*node;
    *tail = *node;
    *node = (*node)->next;
}


shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2){
   shared_ptr<ListNode<int>>dummy_head(new ListNode<int>);
   auto tail = dummy_head;
   while(L1 && L2){
       AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
   }
   tail->next = L1? L1: L2;
   return dummy_head->next;
}


void ReverseList(Node* n, int  beg, int end){
    int p = beg-2;
    int f = end-beg+p-1;
    Node *ps = n, *fe;
    cout << p << " " << f << "\n";;
    //return;
    for(int i = 0; i < p; i++) ps = ps->next;
    fe = ps;
    for(int i =p; i <= f; i++) fe = fe->next;
    cout << ps->v << " !! "  << " " << ps->next->v << " " << fe-> v <<"\n";
    //return;
    
    Node * prev = ps, *curr = ps->next, *next = curr->next;
    //ps->next = fe->next;;
    //curr->next = fe->next;
    prev->next = fe->next->next;
    prev = curr;
    curr= next;
    cout << prev->v << " ?? " << curr->v << " " << fe->v << " " << fe->next->v <<  "\n";
    while(curr != fe){
        next = curr->next;
        
        curr->next = prev;
        prev = curr;
        curr = next;;
        cout << curr->next-> v << " " << curr->v <<  " " << prev->v << "\n";
        
    }
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
    nl.printList();

   // while(hd){
       //cout << hd->v << " ";
       //hd = hd->next;
    //}
    ReverseList(hd, 6, 11);
    nl.printList();

}



