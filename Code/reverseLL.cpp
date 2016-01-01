//
//  reverseLL.cpp
//  Code
//
//  Created by Mahesh  Yadangi.
//  Copyright (c) 2015 Mahesh. All rights reserved.
//

#include <iostream>

using namespace std;

//node in a linked list
template typename<T>
class node_t{
    T data;
    shared_ptr<node_t<T>> next;
};


//Reverse a singly linked list
//Recursion takes o(n) space

//Iterative implementation

template<typename T>
shared_ptr<node_t<T>> reverse_linked_list(shared_ptr<node_t<T>>& head) {
    shared_ptr<node_t<T>> prev = nullptr, curr=head;
    
    while(curr) {
        shared_ptr<node_t<T>> temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

//Write a function to remove k-th last element from L

//Approach: advance a pointer by k elements

template<typename T>
void remove_kth_last(shared_ptr<node_t<T>>& head) {
    shared_ptr<node_t<T>> advance = curr = head;
    
    while(k-- && advance) {
        advance = advance->next;
    }
    
    if(k) {
        throw length_error("not enough nodes in the list");
    }
    
    shared_ptr<node_t<T>> prev = nullptr;
    while(advance) {
        prev=curr;
        curr=curr->next;
        advance = advance->next;
    }
    if(prev) {
        prev->next=curr->next;
        curr=nullptr;
    }
}

//delete a node in o(1) time

template<typename T>
void remove_from_list(shared_ptr<node_t<T>> &v) {
    v->data = v->next->data;
    v->next= v->next->next;
}


//check if a linked list is palindrome
//1. Find mid point of the list
//2. Reverse the second half of the list
//3. check first half and reversed second half
template<typename T>
bool is_linked_list_a_palindrome(shared_ptr<node_t<T>> L) {
    
    shared_ptr<node_t<T>> slow = fast = L;
    while(fast) {
        fast = fast->next;
        if(fast) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    //Now slow will point to the mid point in the list
    slow = reverse_linked_list(slow);
    while (L && slow) {
        if(L->data != slow->data) {
            return false;
        }
        reverse = reverse->next;
        slow = slow->next;
    }
    return true;
}

//Zipping a list
























