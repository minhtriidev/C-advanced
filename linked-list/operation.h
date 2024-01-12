#ifndef __OPERATION_H
#define __OPERATION_H

/*
* File: operation.h
* Author: Tran Minh Tri
* Date: 12/01/2023
* Description: This is a file include some basic operations of linked list
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node
{
    int value;
    struct node* next;
}node;

node *createNode(int value); 
void push_back(node** array, int value); 
void push_front(node **array, int value); 
void pop_back(node **array); 
void pop_front(node **array); 
int front(node *array); 
int back(node *array); 
void insert(node **array, int value, int pos); 
void deletee(node **array, int pos); 
int size(node **array);
int get_value(node *array, int pos); 
bool empty(node **array); 

#endif