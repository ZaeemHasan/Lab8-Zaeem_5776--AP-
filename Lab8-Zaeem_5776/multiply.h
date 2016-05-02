#ifndef _myfile2
#define _myfile2

#define SIZE 512
#define NUM_THREADS 32

struct v 
{
   int i; /* row */	
   int j; /* column */
};

void *multiply(void *param);

#endif
