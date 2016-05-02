#include "multiply.h"
#define SIZE 512

int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

void *multiply(void *param) {
	struct v *data = param; 				// the structure that holds our data
	int sum = 0; 
	int counter=data->i;	
	int limit=counter-(counter / NUM_THREADS);		//the counter 
	   

	for (int m= counter; m >= limit; m--){  
	   for(int n = 1; n <= SIZE; n++){
	       	for(int p = 1; p <= SIZE; p++)
	       		sum += A[m-1][p-1] * B[p-1][n-1];
	       C[m-1][n-1] = sum;
	       sum=0;
	    }
	}
  						 	
	pthread_exit(0);
}
