//
//  medianLL.cpp
//  Code
//  Given a reference to an arbitrary node in a sorted linked list, Find the median
//  Created by Mahesh  Yadangi
//  Copyright (c) 2015 Mahesh. All rights reserved.
//

#include <iostream>

template<typename T>
class node_t {
    T data;
    shared_ptr<node_t<T>> next;
};

/* Solution
   Count the number of nodes and the smallest element in the sorted list
   Then median is n/2 (even) or avg of n/2 and n/2+1 elements
   Should also take care of the case if all the elements in the list are equal
 */

template<typename T>
T median_of_linked_list(const shared_ptr<node_t<T>>& n) {
    shared_ptr<node_t<T>> start, current = n;
    bool is_idential = true;
    int count=0;
    
    do {
        if(current->data != current->next->data) {
            is_idential = false;
        }
        count++;
        //Advance start to find the largest element
        if(start->data <= start->next->data) {
            start=start->next;
        }
    }while(current!=n);
    //handle the case when all elements are identical
    if(is_idential==true) {
        return 0;
    }
    //point to smallest element
    start = start->next;
    for(int i=0; i< (count-1) >>1 ; ++i) {
        start =  start->next;
    }
    return count & 1? start->data : 0.5 * (start->data + start->next->data);
        
    
}
