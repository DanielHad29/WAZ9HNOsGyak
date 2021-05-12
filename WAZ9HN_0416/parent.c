#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
	int status, pid, ppid, gpid;
	
	ppid = getpid();
	
	if ((pid=fork())==0)
	{
	status=execl("/home/daniel/gyerek","/home/daniel/gyerek", NULL);
		if(status==-1)
		{
		perror("parent execl failed");
		exit (0);
		}
	}
	
	printf("\n %d.sz.szulo var a %d.sz.gyerekre.\n", ppid,pid);
	if(pid!=wait(&status)) perror("szulo-varakozas hiba");
	
	return 0;
}
