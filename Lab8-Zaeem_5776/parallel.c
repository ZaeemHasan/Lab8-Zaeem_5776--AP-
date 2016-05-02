#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


#define M 512
#define K 512
#define N 512

#define NUM_THREADS 32	//number of threads being used

int A [M][K];				//Matrix A
int B [K][N];				//Matrix B
int C [M][N];				//Matrix A*B




struct v 
{
   int i; /* row */	
   int j; /* column */
};

void *multiply(void *param); /* the thread */

int main(int argc, char *argv[]) {

   int i,j, count = 0;
   srand (time(NULL));

   for(i=0; i < M; i++){			//add values for matrix A
	for(j=0; j < K; j++){
		A[i][j]=rand() % 10;

	}
    }

   for(i=0; i < K; i++){			//add values for matrix B
	for(j=0; j < N; j++){
		B[i][j]=rand() % 10;
	}
    }
	     

   for(i = 1; i <= NUM_THREADS; i++) {
      
         struct v *__restrict__ data;data = (struct v *) malloc(sizeof(struct v));
         data->i = M/i;		//2
         data->j = K/i;		//2

         pthread_t tid;       //Thread ID
         pthread_attr_t attr; //Set of thread attributes

        
         pthread_attr_init(&attr);
        
	 if(pthread_create(&tid,&attr,multiply,data))
		printf("Error creating thread\n");

         pthread_join(tid, NULL);
         count++;
    }

}

void *multiply(void *param) {
   struct v *data = param; 					// the structure that holds our data
   int n, sum = 0; 
   int m,p;
   int counter=data->i;	
   int limit=counter-(counter / NUM_THREADS);			//the counter 
   

for (m= counter; m >= limit; m--){  
   for(n = 1; n <= N; n++){
       	for(p = 1; p <= K; p++)
       {
	   sum += A[m-1][p-1] * B[p-1][n-1];
       }
       C[m-1][n-1] = sum;
       sum=0;
    }
}
  						 	
   pthread_exit(0);
}
