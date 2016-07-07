//
//  main.cpp
//  DLL
//
//  Created by Justin on 7/5/16.
//  Copyright © 2016 Justin Chang. All rights reserved.
//

#include <iostream>
#include "DLL.h"
#include "OrderedDLL.h"

using namespace std;
int main(int argc, const char * argv[]) {
    DLL<int> dll;
    dll.insert_front(2);
    dll.insert_front(1);
    dll.insert_back(3);
    dll.remove_front();
    dll.remove_back();
    dll.display_list();
    cout << "---" << endl;
    dll.display_backwards();
    
    cout << endl << "------------" << endl << endl;
    
    OrderedDLL<int> odll;
    odll.insert(2);
    odll.insert(1);
    odll.insert(3);
    odll.display_list();
    cout << "---" << endl;
    odll.display_backwards();
    return 0;
}
