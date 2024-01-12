/*
* File: main.c
* Author: Tran Minh Tri
* Date: 12/01/2023
* Description: This is a file include some basic operations of linked list
*/

#include "operation.h"


int main()
{
    node* arr = NULL;
    push_back(&arr, 2);
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);

    printf("Value test: %d\n", empty(&arr));

 //   deletee(&arr, 2);

 //   printf("Value test: %d\n", get(arr, 2)); // in ra 10

 //   printf("Value test: %d\n", get(arr, 5)); // in ra 0

    return 0;
}
