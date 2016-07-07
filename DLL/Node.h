//
//  Node.h
//  DLL
//
//  Created by Justin on 7/5/16.
//  Copyright © 2016 Justin Chang. All rights reserved.
//

#ifndef Node_h
#define Node_h

template <class T>
class Node {
public:
    T val;
    Node *prev, *next;
    Node();
};

template <class T>
Node<T>::Node(): val(0), prev(nullptr), next(nullptr) {};

#endif /* Node_h */
