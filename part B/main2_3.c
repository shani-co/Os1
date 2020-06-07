
#include <syslog.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define Cycles 2
#define time 1000000

void sleepfunc( )
{
	int i=0;
	for (i=0 ; i<Cycles; i++)
	{
		
		usleep(time);
	}
}


int main(){

	//create child that will be deamon 
	pid_t pid =fork();

	if(pid == 0){
		//we are in child
		//move to root dir , used to not block the file system
		chdir("/");

		//move the child to another session, so the paren may be closed
		setsid();

		printf("starting my daemon\n*");

		//close output chanels
		close(stdout);
		close(stdin);
		close(stderr);
		
		//open log
		openlog ("myDeamon",LOG_PID, LOG_DAEMON);
		syslog (LOG_NOTICE, "daemon started");
		usleep(3000000);
		syslog (LOG_NOTICE, "doing some work.....");
		usleep(3000000);
		syslog (LOG_NOTICE, "daemon fintshed");
		
	}
	else{
		printf("daemon PID %d\n",pid);
}

sleepfunc();
return 0;

}
