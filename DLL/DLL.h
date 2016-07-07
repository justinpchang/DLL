//
//  DLL.h
//  DLL
//
//  Created by Justin on 7/5/16.
//  Copyright © 2016 Justin Chang. All rights reserved.
//

#ifndef DLL_h
#define DLL_h

#include "Node.h"
#include <iostream>

// DLL class definition
template <class T>
class DLL {
    Node<T> *head, *tail, *p = nullptr, *t = nullptr, *r = nullptr;
    
public:
    DLL();
    
    ~DLL();
    
    void insert_front(T val);
    
    void insert_back(T val);
    
    void remove_front();
    
    void remove_back();
    
    void display_list();
    
    void display_backwards();
};


// constructor
template <class T>
DLL<T>::DLL() {
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    head->prev = tail;
    tail->prev = head;
    tail->next = head;
}

// destructor
template <class T>
DLL<T>::~DLL() {
    p = head->next;
    while(p->next != head) {
        p = p->next;
        delete p->prev;
    }
    delete head;
    delete tail;
}

// insert a node at the start of the with the value of the passed parameter
template <class T>
void DLL<T>::insert_front(T val) {
    // create new element node
    p = new Node<T>();
    p->val = val;
    
    // put it at the start
    p->next = head->next;
    head->next = p;
    p->next->prev = p;
    p->prev = head;
}

// insert a node at the back of the list
template <class T>
void DLL<T>::insert_back(T val) {
    // create new element node
    p = new Node<T>();
    p->val = val;
    
    // put it at the end
    p->prev = tail->prev;
    tail->prev = p;
    p->prev->next = p;
    p->next = tail;
}

// remove an element from the list
template <class T>
void DLL<T>::remove_front() {
    p = head->next;
    head->next = p->next;
    p->next->prev = head;
    delete p;
}

// remove an element from the back of the list
template <class T>
void DLL<T>::remove_back() {
    p = tail->prev;
    tail->prev = p->prev;   
    p->prev->next = tail;
    delete p;
}

// print all the nodes from front to back
template <class T>
void DLL<T>::display_list() {
    p = head->next;
    while(p->next != head) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
}

// print all the nodes in reverse order
template <class T>
void DLL<T>::display_backwards() {
    p = tail->prev;
    while(p->prev != tail) {
        std::cout << p->val << std::endl;
        p = p->prev;
    }
}

#endif /* DLL_h */
