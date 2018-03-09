/**
 *  Integer Stack ADT : public interface
 *    Choose your implementation of a stack
 *
 *  COMP220: Lab 7 Solution
 *  Original Author:  Joseph Fall 
 *  Modified by:  
 *  Date:    Mar. 6, 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "istack.h"

/*********************
 *  PUBLIC INTERFACE
 *********************/
 
 stackNode_t* createNode(int value)
 {
     stackNode_t* newNode = malloc(sizeof(stackNode_t));
     newNode->data = value;
     newNode->next = NULL;
     return newNode;
 }
/*
 * Constructor - return a new, empty stack 
 * POST: istackIsEmpty(stack)
 */
IntStack_t istackCreate( )
{
    stackNode_t* dummy = createNode(INT_MIN);
    IntStack_t stack = {dummy};
    return stack; 
}

/*
 * Destructor - empty stack and free all associated memory
 */
 void istackDestroy( IntStack_t *stack )
 {
    stackNode_t* q = stack->head->next;
  
  printf("\n");
  
  while(q != NULL){
    q = q->next;
    printf("Freeing the node [%d]\n",stack->head->next->data);
    free(stack->head->next);
    stack->head->next = q;
    }
 }

/*
 * Print a text representation of this stack on STDOUT
 */
void istackPrint( IntStack_t stack  )
{
    stackNode_t* p = stack.head->next;
  
    while(p != NULL){
        if (p == stack.head->next) {
          printf("h");
        }
        
        printf("[%d]", p->data);
        
        if (p->next ==NULL) {
          printf("-|");
        } else {
          printf("-->");
        }
        p = p->next;
      }
    printf("\n");
}

/*
 * Return true iff the stack is empty
 */
bool istackIsEmpty( IntStack_t stack )
{
    return stack.head->next == NULL;
}

/*
 * Return true iff the stack is full
 */
bool istackIsFull( IntStack_t stack )
{
    return false;
}

/*
 * Examine the item at the top of the stack
 * PRE: ! istackIsEmpty( stack )
 */
int istackTop( IntStack_t stack )
{
    return stack.head->next->data;
}

/*
 * Pop the item from the top of the stack 
 * PRE: ! istackIsEmpty( stack )
 */
int istackPop( IntStack_t *stack )
{   
    
    stackNode_t* popNode = stack->head->next;  
    
    int value = popNode->data;
    
    stack->head->next = popNode->next;
    
    free(popNode);
    
    return value;
    
}

/*
 * Push given item on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
int istackPush( IntStack_t *stack, int item)
{
    stackNode_t* newNode = createNode(item);
    
    newNode->next = stack->head->next;
    stack->head->next = newNode;
    
    return newNode->data;
    
    
}
