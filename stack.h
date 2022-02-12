/*
 * stack.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dchiu
 */

#ifndef STACK_H_
#define STACK_H_

//structs
typedef struct Node
{
	double data;
    struct Node *next;
} Node;

//functions declarations

int size();
void push(double input);
double pop();
void printStack();

#endif /* STACK_H_ */
