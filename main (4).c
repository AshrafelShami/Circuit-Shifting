/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

unsigned int rcshift(unsigned int, unsigned int);
unsigned int lcshift(unsigned int, unsigned int);

void main(void){
	unsigned int n = 0xAABBCCDD;
	unsigned int num = 16;

	printf("Before: %x\n", n);
	n = rcshift(n, num);
	printf("After right: %x\n", n);
	n = lcshift(n, num);
	printf("After left: %x\n", n);
    getchar();
	return;
}

unsigned int rcshift(unsigned int number, unsigned int shifts){
	unsigned int mask = ~0;
	unsigned int temp = 0;
	/* Adjust mask to map to left most bits to be moved to right */ 
	
	/* Store bits to be masked in temp */
	temp = number;
	
	/* Do right shift for original number */ 
	number = number >> shifts;
	
	/* Store bits stored in temp in the right most bits location of number */ 
	mask = mask << shifts;
	mask = ~mask;
	mask &= temp;
	mask = (mask << (32 - shifts));
	number |= mask;
	// End of your code 
	return number;
}
unsigned int lcshift(unsigned int number, unsigned int shifts){
	unsigned int mask = ~0;
	unsigned int temp = 0;
	// Add your code here  
	/* Adjust mask to map to right most bits to be moved to left */ 
	temp = number;
	/* Store bits to be masked in temp */ 

	/* Do left shift for original number */ 
	number = number << shifts;
	/* Store bits stored in temp in the left most bits location of number */ 
	mask = mask >> shifts;
	mask = ~mask;
	mask &= temp;
	mask = (mask >> (32 - shifts));
	number |= mask;
	// End of your code 
	return number;
}