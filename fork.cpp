#include<stdio.h>
#include<sys/types.h>
void cp(int);
void pp(int);
main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		cp(pid);
	}
	else 
	if(pid>0)
		pp(pid);
	else
	    printf("\nFork Error");
}
void cp(int pid)
{
	printf("\nChild Process..");
	printf("\nChild ID :%d",getpid());
	printf("\nParent ID :%d\n",getppid());
}
void pp(int pid)
{
	printf("\nParent Process..");
	printf("\nParent ID :%d",getpid());
	printf("\nChild ID :%d",pid);
}

