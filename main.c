
#include <stdio.h>

typedef unsigned int u32;

u32 rcshift(u32, u32);
u32 lcshift(u32, u32);

void main(void){
	u32 n = 0xAABBCCDD;
	u32 num = 16;

	printf("Before: %x\n", n);
	n = rcshift(n, num);
	printf("After right: %x\n", n);
	n = lcshift(n, num);
	printf("After left: %x\n", n);
    getchar();
	return;
}

u32 rcshift(u32 number, u32 shifts){
	u32 mask = ~0;
	u32 temp = 0;
	/* Adjust mask to map to left most bits to be moved to right */ 
	mask = mask << shifts;
	mask = ~mask;
	
	/* Store bits to be masked in temp */
	temp = number;
	
	/* Do right shift for original number */ 
	number = number >> shifts;
	
	/* Store bits stored in temp in the right most bits location of number */ 
	mask &= temp;
	mask = mask << ((sizeof(number)*8) - shifts);
	number |= mask;
	
	return number;
}
u32 lcshift(u32 number, u32 shifts){
	u32 mask = ~0;
	u32 temp = 0;

	/* Adjust mask to map to right most bits to be moved to left */ 
	mask = mask >> shifts;
	mask = ~mask;
	
	/* Store bits to be masked in temp */ 
	temp = number;
	/* Do left shift for original number */ 
	number = number << shifts;
	/* Store bits stored in temp in the left most bits location of number */ 
	mask &= temp;
	mask = mask >> ((sizeof(number)*8) - shifts);
	number |= mask;
	
	return number;
}
