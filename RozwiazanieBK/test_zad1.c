#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <lib.h>
#include <minix/type.h>
#include <minix/callnr.h> 

int main()
{
	message m, new_m;
	int i;
	printf("\nZadanie 1 (numer 1)\n");
	_syscall(MM, 78, &m); 
	printf("\n[Before] PID of process with max amount of children: %d\n", m.m1_i1); 
	printf("[Before] Amount of his children: %d\n", m.m1_i2);	
	for(i = 0; i < 20; i++)
	{
		if(fork() == 0)
		{
			sleep(1);
			return 0;	
		}
	}
	_syscall(MM, 78, &new_m);
	printf("\n[After] PID of process with max amount of children: %d\n", new_m.m1_i1);
	printf("[After] Amount of his children: %d\n\n", new_m.m1_i2);
	return 0;
} 
