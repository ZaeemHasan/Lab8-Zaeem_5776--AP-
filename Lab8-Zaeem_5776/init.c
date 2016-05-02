#include <stdlib.h>
#include <time.h>
#include "init.h"
#define SIZE 512

void init_matrix(int mat[SIZE][SIZE])
{ 
	srand (time(NULL));
	for(int i=0; i < SIZE; i++){			
		for(int j=0; j < SIZE; j++){
			mat[i][j]=rand() % 10;
		}
	}	
}
