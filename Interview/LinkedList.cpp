//
//  LinkedList.cpp
//
//  Let L and F be singly linked list of numbers.
//  Assume the numbers in L and F appear in sorted order within the lists.
//  The merge of L and F is a list consisting of the nodes of L and F in which
//  keys appear in sorted order.
//
//  Write a function that takes L and F, and returns the merge of L and F
//  Your code should use O(1) additional storage
//  The only field you can change in a node is next
//
//  Created by Mahesh  Yadangi on 29/12/15.
//  Copyright (c) 2015 Mahesh. All rights reserved.
//

#include <iostream>

using namespace std;


//prototype of singly linked list in c++
template<typename T>
class node_t {
    T data; //data field
    shared_ptr<node_t<T>> next; //next field
};

template <typename T>
void append(shared_ptr<node_t<T>>& head, shared_ptr<node_t<T>>& tail, shared_ptr<node_t<T>>& n) {
    head ? tail->next = n : head = n;
    tail = n; //reset tail to the last node
}

template <typename T>
void append_node_and_advance(shared_ptr<node_t<T>>& head, shared_ptr<node_t<T>>& tail, shared_ptr<node_t<T>>& n) {
    append(head,tail,n);
    n = n->next; //advance n
}


//Merge Sorted Linked Lists (singly Linked Lists)
template <typename T>
shared_ptr<node_t<T>> merge_sorted_linked_lists(shared_ptr<node_t<T>> L, shared_ptr<node_t<T>> F) {
    shared_ptr<node_t<T>> sorted_head= nullptr, tail = nullptr;
    while(L && F) {
        append_node_and_advance(sorted_head, tail, L->data < F->data ? L : F);
    }
    if(L) {
        append(sorted_head,tail,L);
    }
    if(F) {
        append(sorted_head,tail,F);
    }
    return sorted_head;
}






