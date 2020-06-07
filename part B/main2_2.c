#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100000
#define CYCLES 2


char child_stack [STACK_SIZE+1];

void print(const char *text){
	int i;
	for (i=0;i<CYCLES;i++){
		printf("Hello from %s\n",text);
		usleep(1000000);
	}
}

int child(void * params) {
		
		print("child_threed");
}

int main(){

		
		int result = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
		printf("clone result = %d\n ", result);
		int result2 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
		printf("clone result = %d\n ", result2);
		printf("parent");
			
		return 0;
}
