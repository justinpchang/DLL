//
//  OrderedDLL.h
//  DLL
//
//  Created by Justin on 7/7/16.
//  Copyright © 2016 Justin Chang. All rights reserved.
//

#ifndef OrderedDLL_h
#define OrderedDLL_h

#include "DLL.h"

template <class T>
class OrderedDLL {
    Node<T> *head, *tail, *p = nullptr, *t = nullptr, *r = nullptr, *q = nullptr;
    
public:
    OrderedDLL();
    
    ~OrderedDLL();
    
    void insert(T val);
    
    void remove_front();

    void remove_back();
    
    void display_list();
    
    void display_backwards();
};

// constructor
template <class T>
OrderedDLL<T>::OrderedDLL() {
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    head->prev = tail;
    tail->prev = head;
    tail->next = head;
}

// destructor
template <class T>
OrderedDLL<T>::~OrderedDLL() {
    p = head->next;
    while(p->next != head) {
        p = p->next;
        delete p->prev;
    }
    delete head;
    delete tail;
}

// insert a node with the value of the passed parameter
template <class T>
void OrderedDLL<T>::insert(T val) {
    // create new element node
    p = new Node<T>();
    p->val = val;
    
    // find the correct place (need to insert in front of t)
    t = head->next;
    while(t->next != head) {
        if(p->val <= t->val)
            break;
        t = t->next;
    }
    r = t->prev;
    t->prev = p;
    t->prev->prev = r;
    t->prev->next = t;
    r->next = p;
}

// remove an element from the list
template <class T>
void OrderedDLL<T>::remove_front() {
    p = head->next;
    head->next = p->next;
    p->next->prev = head;
    delete p;
}

// remove an element from the back of the list
template <class T>
void OrderedDLL<T>::remove_back() {
    p = tail->prev;
    tail->prev = p->prev;
    p->prev->next = tail;
    delete p;
}

// print all the nodes from front to back
template <class T>
void OrderedDLL<T>::display_list() {
    p = head->next;
    while(p->next != head) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
}

// print all the nodes in reverse order
template <class T>
void OrderedDLL<T>::display_backwards() {
    p = tail->prev;
    while(p->prev != tail) {
        std::cout << p->val << std::endl;
        p = p->prev;
    }
}


#endif /* OrderedDLL_h */
