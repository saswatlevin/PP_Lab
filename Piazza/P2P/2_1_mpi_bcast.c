//Author : Amitkumar Vinayak Gundad
//Date : 09/01/2019
//This example simply uses MPI_Bcast to broadcast a read in value to all other processes from root process.

#include <stdio.h>
#include "mpi.h"

int main(int argc,char **argv)
{
	int rank, value;
    
	MPI_Init(&argc, &argv);
    	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

    	if (rank == 0) 
	{
        	// if root process we read the value to broadcast
        	printf("Enter a number to broadcast:\n");
	    	scanf("%d", &value);
    	} 
	else 
	{
    		printf("process %d: Before MPI_Bcast, value is %d\n", rank, value); 
	}

    	// each processor calls MPI_Bcast, data is broadcast from root processor andends up in everyone value variable
	// root process uses MPI_Bcast to broadcast the value, each other process uses MPI_Bcast to receive the broadcast value

    	MPI_Bcast(&value, 1, MPI_INT, 0, MPI_COMM_WORLD);

    	printf("process %d: After MPI_Bcast, value is %d\n", rank, value);

    	MPI_Finalize();

	return 0;
}

