#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print (const char *text){
	
			int i;
			for (i=0;i<2;i++){
						printf("Hello from %s\n",text);
						usleep(1000000);
			}
}

int  main()
{
	
				//creat child	
				pid_t pid = fork();
	
				if (pid == 0){
							//we are in child	
		
							//creat a grand child
							pid_t pid = fork();
		
							if( pid== 0){
										//we are in grang child
										print("grand child");

		
		
							}
							else{
										print("chaild");
							}
				}	
				else{
							print("parent\n");
				}
				printf ("done\n");
				
				return 0;
}
