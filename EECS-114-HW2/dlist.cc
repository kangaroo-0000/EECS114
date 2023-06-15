#include "dlist.h"
#define NULL 0
DList::DList()
{
  /* initialize empty list */
  head = NULL;
  tail = NULL;
}

void DList::add_to_front(int value){
    ListNode* temp = new ListNode;
    temp->val = value;
    temp->next = head;
    temp->prev = NULL;
    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
    if (tail == NULL)
    {
        tail = temp;
    }
}

void DList::add_to_back(int value){
    ListNode* temp = new ListNode;
    temp->val = value;
    temp->next = NULL;
    temp->prev = tail;
    if (tail != NULL)
    {
        tail->next = temp;
    }
    tail = temp;
    if (head == NULL)
    {
        head = temp;
    }
}

int DList::first(){
    if (head == NULL)
    {
        return 0;
    }
    return head->val;
}

int DList::last(){
    if (tail == NULL)
    {
        return 0;
    }
    return tail->val;
}

void DList::remove(ListNode* node){
    if (node == NULL)
    {
        return;
    }
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    else
    {
        head = node->next;
    }
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }
    else
    {
        tail = node->prev;
    }
    delete node;
}

ListNode* DList::previous(ListNode* node){
    if (node == NULL)
    {
        return NULL;
    }
    return node->prev;
}

ListNode* DList::next(ListNode* node){
    if (node == NULL)
    {
        return NULL;
    }
    return node->next;
}       

ListNode* DList::search_value(int value){
    ListNode* temp = head;
    while (temp != NULL)
    {
        if (temp->val == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}