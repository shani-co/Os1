#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <syslog.h>

#define Stack_Size 10000
#define Cycles 2
#define time 1000000

char Stack_Child[Stack_Size+1];


void sleepfunc( const char *c)
{
	int i=0;
	for (i=0 ; i<Cycles; i++)
	{
		printf("this is : %s\n", c);
		usleep(time);
	}
}
	int childs( void *v)
	{
		char *args [2] = {"./out1" , NULL};
		execvp (args[0] ,args);
		sleepfunc("childs");
		
	}
	
	int clones( void *v)
	{
		char *args [2] = {"./out2" , NULL};
		execvp (args[0] ,args);
		sleepfunc("clones");
		
	}


int main ( ) 
{
	int res = clone (childs , Stack_Child+Stack_Size ,CLONE_PARENT ,0);
	printf("childs started ! = %d\n" ,res);
	int res2 = clone (clones , Stack_Child+Stack_Size ,CLONE_PARENT ,0);
	printf("clone started ! = %d\n" ,res2);
	char *args [2] = {"./out3" , NULL};
		execvp (args[0] ,args);
		
		return 0;
		
}
	
















































































































































































