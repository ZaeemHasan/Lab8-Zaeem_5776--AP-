#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "init.h"
#include "multiply.h" 
#define SIZE 512  

int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
 
int main(int argc, char* argv[])
{
	int count = 0;
  
	init_matrix(A);
	init_matrix(B);
  

	for(int i = 1; i <= NUM_THREADS; i++) {
      		struct v *__restrict__ data;
		data = (struct v *) malloc(sizeof(struct v));
		data->i = SIZE/i;		//2
		data->j = SIZE/i;		//2

		pthread_t tid;       //Thread ID
		pthread_attr_t attr; //Set of thread attributes

        	pthread_attr_init(&attr);
        
		if(pthread_create(&tid,&attr,multiply,data))
			printf("Error creating thread\n");

        	pthread_join(tid, NULL);
        	count++;
	}

 
  return 0;
 
}
