/*
 ============================================================================
 Name        : PolishSol.c
 Author      : bgamble01
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "polish.h"

#define MAX_EQ_LEN 100 /* maximum RPN expression input length */

int main()
{
	char eqn[MAX_EQ_LEN];	 // string to store the input RPN expression
	char resp[MAX_EQ_LEN];  //string to store the user's response "y" or "n"

	int program=1;
	double ans;

	while(program == 1){
		printf("\nEnter an equation (in RPN): \n");
		fgets(eqn, MAX_EQ_LEN-1,stdin);
		ans = evaluate(eqn);
		if(isnan(ans)){
		
		}
		else{
			printf("\n%.3f\n\n",ans);
		}

		printf("Evaluate another? (y/n): ");
		fgets(resp, MAX_EQ_LEN-1,stdin);
		if(resp[0]=='y'){

		}
		else{
			program = 0;
		}
	}
	printf("Exiting...\n");
	return 0;
}
