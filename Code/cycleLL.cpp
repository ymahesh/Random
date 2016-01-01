//
//  cycleLL.cpp
//  Given a reference to the head of a singly Linked list L, how would you
//  determine whether L ends in a null or reaches cycle of nodes? Write a
//  function that returns null if there does not exist a cycle, and
//  reference to the start of a cycle if a cycle is present
//  Created by Mahesh  Yadangi
//  Copyright (c) 2015 Mahesh. All rights reserved.
//


/* Solution:
   1. Store the visited nodes in a hash table. If we visit a node already visited
      then a cycle exists else the search ends at the tail. But this requires o(n) space
   2. Memory is allocated on word boundaries and atleast two of the least significant 
      bits in the next pointer are 0. Bit fiddling can be done to set the least significant
      bit on the next pointer to mark the node as visited. But this needs a change 
      in the data structure. 
   3. Reverse a linked list
   4. Naive approach- o(n2) two loops. Outer loop visits the node one-by-one and
      inner loop visits starts from head.
 
   5. Tortoise - Hare solution. Two pointers (fast and slow)
      Let cycle be of length n starting at m. Assume both meet at i.
      2 * (m+i) = m+n+i => m= n-i (Ds/Ss = Df/Sf)
 */

#include <iostream>


template<typename T>
class node_t {
    T data; //data object
    shared_ptr<node_t<T>> next;
};

template<typename T>
shared_ptr<node_t<T>> hascycle(const shared_ptr<node_t<T>>& head) {
    shared_ptr<node_t<T>> fast = head, slow = head;
    
    while(slow && slow->next && fast && fast->next, fast->next->next) {
        slow= slow->next, fast=fast->next->next;
        if(slow == fast) { //Found cycle
            slow = head;
            while(slow!=fast) {
                slow=slow->next;
                fast=fast->next;
            }
            return slow; //this is start of the cycle
        }
    }
    return nullptr;
}
















