/*
 * polish.c
 *
 *  Created on: Feb 11, 2022
 *      Author: bgamble01
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "stack.h"
#include "polish.h"


/**
 * Performs RPN calculations and returns output
 * @param input String of user input to evaluate
 * @return evaluation of the RPN expression
 */
double evaluate(char input[]){

    int length = strlen(input);
    int check;
    double first;
    double second;
    double ans;
    double num;
    char ex[length];
    strcpy(ex,input);

    char * split;
	split = strtok(ex," ");
	while(split != NULL){
         //case if the input is an operator
        if(ispunct(split[0])!=0){
            check = (int) split[0];
            if (check==43||check==45||check == 42||check == 47){
                if(size()<2){
                    while(size()!=0){ //cleans stack
                      pop();
                    }
                    printf("Error: insufficient operands.\n\n");
                    return NAN;
                }
                else{
                    second = pop();
                    first = pop();
                    if(check==42){  //multiplication
                        ans = first*second;
                        push(ans);
                    }
                    else if(check==43){ //additionn
                        ans = first+second;
                        push(ans);
                    }
                    else if(check==45){ //subtraction
                        ans = first-second;
                        push(ans);
                    }
                    else{
                        if(second==0){ //division
                            printf("Error: divide by zero\n\n");
                            return NAN;
                        }
                        else{
                            ans = first/second;
                            push(ans);
                        }
                    }


                }
            }
            else{ //must mean that punctuation exists that is not correct
                printf("Error: invalid operator found\n\n");
                return NAN;
            }

        }
        //if the token is not an operator
        else{
            num = atof(split);
            push(num);
        }
			
		split = strtok(NULL, " ");
	}

    
    if(size()>1){
        printf("Error: too many operands\n\n");
        while(size()!=0){ //cleans stack
            pop();
        }
        return NAN;
    }
    else{
        return pop();
    } 
}    
