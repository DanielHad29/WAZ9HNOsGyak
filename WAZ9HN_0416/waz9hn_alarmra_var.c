#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#define SECOND 1

void do_nothing();

int main()
{
	int i;
	unsigned sec=1;
 for(i=1;i<8;i++)
 {	
 	alarm(sec);
	signal(SIGALRM, do_nothing);
	printf(" %d varok de meddig?\n", i);
	pause();
	printf("Vegre itt az alarm \n");
 }
}
void do_nothing(){;}

