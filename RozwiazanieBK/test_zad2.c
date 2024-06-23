#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <lib.h>
#include <minix/type.h>
#include <minix/callnr.h>

int main(int argc, char **argv)
{
	message m, new_m;
	int i, j, k, l;
	int pid_to_skip = atoi(argv[1]);
	m.m1_i1 = pid_to_skip;
	printf("\nZadanie 2 (numer 3)\n");
	_syscall(MM, 79, &m);
	printf("\n[Before] PID of process with max amount of descendants: %d\n", m.m1_i1);
	printf("[Before] Amount of his descendants: %d\n", m.m1_i2);
	for(i = 0; i < 2; i++)
	{
		if(fork() == 0)
		{
			for(j == 0; j < 2; j++)
			{
				if(fork() == 0)
				{
					for(k = 0; k < 1; k++)
					{
						if(fork() == 0)
						{
							for(l = 0; l < 2; l++)
							{
								if(fork() == 0)
								{
									sleep(1);
									return 0;
								}
							}
							sleep(1);
							return 0;
						}
					}
					sleep(1);
					return 0;
				}
			}
			sleep(1);
			return 0;
		}
	}
	_syscall(MM, 79, &new_m);
	printf("\n[After] PID of process with max amount of descendants: %d\n", new_m.m1_i1);
	printf("[After] Amount of his descendants: %d\n\n", new_m.m1_i2);
	return 0;
}
