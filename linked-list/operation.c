/*
* File: operation.c
* Author: Tran Minh Tri
* Date: 12/01/2023
* Description: This is a file include some basic operations of linked list
*/

#include "operation.h"

/*
* Function: createNode
* Description: create a node in a linked list have 2 member: value of the node and the pointer hold address of the next node
* Input:
*   value - an integer value - value of the member
* Output:
*   ptr - address of the node created
*/
node* createNode(int value)
{
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


/*
* Function: push_front
* Description: add new node to the beginning of the linked list
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of linked list
*   value - an integer value - value of the member
* Output:
*   new list with new node at the beginning position
*/
void push_front(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node

    temp->next = *array;
    *array = temp;
}


/*
* Function: push_back
* Description: add new node to the last of the linked list
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of linked list
*   value - an integer value - value of the member
* Output:
*   new list with new node at the last position
*/
void push_back(node** array, int value)
{
    node* temp;
    temp = createNode(value); // khoi tao node

    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}


/*
* Function: insert
* Description: add new node to the allocated position
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of linked list
*   value - an integer value - value of the member
*   pos - an integer value - the allocated position
* Output:
*   new list with new node at the allocated position
*/
void insert(node** array, int value, int pos) // them 1 node vao mot vi tri bat ky
{
    int i = 0;
    node* temp;
    temp = createNode(value); // khoi tao node

    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL && pos-1 != i) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node
            i++;
        }

        if (pos != i+1)
        {
            printf("Error: List has less element\n");
        }

        p->next = temp;     // change it next member point to address of new node have just create
        p = p->next;
    }
}


/*
* Function: pop_front
* Description: delete a node at the beginning of the linked list
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of linked list
* Output:
*   new list with a deleted node at the beginning of the position
*/
void pop_front(node** array) // xoa node dau tien
{   
    node* p;
    p = *array;

    *array = (*array)->next;

    (p)->next = NULL;
}


/*
* Function: pop_back
* Description: delete a node at the last of the linked list
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of linked list
* Output:
*   new list with a deleted node at the last of the position
*/
void pop_back(node** array)
{
    node* p;
    p = *array;

    while (p->next->next != NULL)     // free the last node in the list
    {
        p = p->next;
    }
    p->next = NULL;

}


/*
* Function: deletee
* Description: delete a node at the allocated position
* Input:
*   array - pointer to pointer has datatype is node - address of pointer array which point to first node of linked list
*   pos - an integer value - the allocated position
* Output:
*   new list with a deleted node at the allocated position
*/
void deletee(node** array, int pos) // xoa 1 node tai mot vi tri bat ky
{
    int i = 0;

    node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
    node* temp;

    while (p->next != NULL && pos - 1 != i) // which mean the current node is not the last node
    {
        p = p->next;    // check next node until it a last node
        i++;
    }

    if (pos != i + 1)
    {
        printf("Error: List has less element\n");
    }

    temp = p; // đi đến phần tử pos-1
    temp = temp->next; // đi đến phần tử pos

    (p->next) = (temp->next); // gán cho next của phần tử pos-1 là địa chỉ phần tử pos+1

    temp->next = NULL; // gán cho next phần tử pos là NULL nhằm xóa nó ra khỏi list

}


/*
* Function: front
* Description: get the value of the beginning node of linked list
* Input:
*   array - pointer has datatype is node - address of first node of linked list
* Output:
*   value of the beginning node of linked list
*/
int front(node* array) // lay gia tri cua node dau tien
{
    int value = array->value;
    return value;
}


/*
* Function: back
* Description: get the value of the last node of linked list
* Input:
*   array - pointer has datatype is node - address of first node of linked list
* Output:
*   value of the last node of linked list
*/
int back(node* array)
{
    while (array->next != NULL)
    {
        array = array->next;
    }

    int value = array->value;
    return value;
}


/*
* Function: get_value
* Description: get the value of the allocated node of linked list
* Input:
*   array - pointer has datatype is node - address of first node of linked list
* Output:
*   value of the allocated node of linked list
*/
int get_value(node* array, int pos)
{
    int i = 0;

    while (array->next != NULL && pos != i)
    {
        array = array->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}


/*
* Function: size
* Description: get the size of linked list with unit is byte 
* Input:
*   array - pointer has datatype is node - address of first node of linked list
* Output:
*   the size of linked list with unit is byte 
*/
int size(node** array) // lay kich thuoc cua list
{
    int size = 0;
    node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist

    if (*array == NULL)   // if array doesn't have any node yet
    {
        size = 0;
    }
    else                // if array has some node
    {
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node
            size++;
        }
    }
    return size+1;
}


/*
* Function: empty
* Description: check the linked list is empty or not empty
* Input:
*   array - pointer has datatype is node - address of first node of linked list
* Output:
*  true - 1 if the linked list is empty
* false - 0 if the linked list is not empty 
*/
bool empty(node** array) // kiem tra list co rong hay khong
{
    if (*array == NULL)   // if array doesn't have any node yet
    {
        return true;
    }
    else
    {
        return false;
    }
}

