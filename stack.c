/*
 * stack.c
 *
 *  Created on: Feb 11, 2022
 *      Author: bgamble01
 */
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int count=0;
Node* top;

/**
 * Returns the number of elments in the stack
 * 
 * @return number of elements in the stack
 */
int size(){
    return count;
}

/**
 * Pushes a new element onto the stack
 *
 * @param	input data to be stored in the element
 */
void push(double input){
    Node *newNode = (Node*) malloc(sizeof(Node));

    if(count==0){
        newNode->data=input;
        newNode->next=NULL;
        top=newNode;
        count++;
    }
    else{
        newNode->data=input;
        newNode->next=top;
        top=newNode;
        count++;
    }

}

/**
 * Removes the top element and returns the top element in the stack
 * 
 * @return the top element
 */
double pop(){
    double temp = top->data;
    if(count ==1){
        free(top);
        top=NULL;
    }
    else{
        Node* remove = top;
        top = top->next;
        free(remove);
    }
    count--;
    return temp;
}

/**
 * Prints the stack
 */
void printStack(){
    Node* curr;

    if(count==0){
        printf("The stack is empty\n");
    }
    else{
        curr = top;
        while(curr!=NULL){
            printf("%f->",curr->data);

            curr = curr->next;
        }

        printf("\n");
    }

}
